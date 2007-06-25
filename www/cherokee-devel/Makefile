# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
DISTVERSION=	0.6.0b700
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/0.6/${PORTVERSION:R}/ \
		CENKES LOCAL/beech
PKGNAMESUFFIX=	-devel

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Extremely fast and flexible web server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFLICTS=	cherokee-[0-9]*
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	cherokee.sh
USE_GCC=	3.4+
USE_BISON=	yes
USE_MYSQL=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man \
		--with-wwwroot=${PREFIX}/www/cherokee \
		--enable-readdir_r \
		--disable-static
DEFCONFS=	cherokee.conf mime.compression.types mime.types
CONFSUBDIRS=	ssl mods-available mods-enabled sites-available sites-enabled
MAN1=		cget.1 cherokee-config.1 cherokee.1 cherokee_logrotate.1

OPTIONS=	OPENSSL	"TLS/SSL support via openssl"	on \
		GNUTLS	"TLS/SSL support via gnutls"	off \
		IPV6	"IPv6 support"			on

.include <bsd.port.pre.mk>

.ifndef WITHOUT_OPENSSL
CONFIGURE_ARGS+=--enable-tls=openssl
.elifdef WITH_GNUTLS
LIB_DEPENDS+=	gnutls.15:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-tls=gnutls
.else
CONFIGURE_ARGS+=--disable-tls
.endif

.ifdef WITHOUT_IPV6
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|@mkdir_p@|${MKDIR} --|g'
	@${MV} ${WRKSRC}/mods-icons.conf.sample ${WRKSRC}/mods-icons.sample
	@${REINPLACE_CMD} -e '/cherokee_replace.*%sysconfdir%/d;/^SUBDIRS/s|doc ||;\
		/^install-data-am/s|install-data-local|install-data-local-config|;\
		/^SUBDIRS/s|windows||'\
		${WRKSRC}/Makefile.in
	@for i in ${BUILD_WRKSRC}/*.sample.pre;do ${SED} -e \
		's:%sysconfdir%:${PREFIX}/etc:g; \
		s:%datadir%:${PREFIX}/share:g; \
		s:%wwwroot%:${PREFIX}/www/cherokee:g; \
		s:%prefix%:${PREFIX}:g; \
		s:#.*User.*nobody:User www:g; \
		s:#.*Group.*nogroup:Group www:g; \
		s:#.*PollMethod.*poll:PollMethod kqueue:g' \
		$$i > $${i%.pre};done

post-install:
	@${INSTALL} -d ${CONFSUBDIRS:S|^|${PREFIX}/etc/cherokee/|}
	@for i in ${DEFCONFS};do\
		${INSTALL_DATA} ${WRKSRC}/$$i.sample ${PREFIX}/etc/cherokee/$$i.default;done
	@${INSTALL_DATA} ${WRKSRC}/performance.conf.sample ${PREFIX}/etc/cherokee/cherokee.conf.perf_sample
	@for i in ${WRKSRC}/mods-*.sample;do\
		${INSTALL_DATA} $$i ${PREFIX}/etc/cherokee/mods-available/$${i#*mods-};done
	@:>${PREFIX}/etc/cherokee/mods-enabled/.empty
	@:>${PREFIX}/etc/cherokee/sites-available/.empty
	@:>${PREFIX}/etc/cherokee/sites-enabled/.empty
	@:>${PREFIX}/etc/cherokee/ssl/.empty
	@for i in `${FIND} ${PREFIX}/etc/cherokee/ -name \*.default`;do\
		if [ ! -f $${i%.default} ];then ${CP} $$i $${i%.default};fi;done
	@for i in `${FIND} ${PREFIX}/etc/cherokee/ -name \*.sample`;do\
		if [ ! -f $${i%.sample} ];then ${CP} $$i $${i%.sample};fi;done

.include <bsd.port.post.mk>
