# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/0.7/0.7.2/ \
		LOCAL/beech
PKGNAMESUFFIX=	-devel

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Extremely fast and flexible web server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFLICTS=	cherokee-[0-9]*
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	cherokee.sh
USE_GCC=	3.4+
USE_BISON=	build
USE_MYSQL=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-wwwroot=${PREFIX}/www/cherokee \
		--enable-readdir_r \
		--disable-static
DEFCONFS=	cherokee.conf
CONFSUBDIRS=	ssl mods-available mods-enabled sites-available sites-enabled
MAN1=		cget.1 cherokee-config.1 cherokee.1 cherokee_tweak.1 \
		cherokee-admin.1 spawn-fcgi.1
PORTDOCS=	*

OPTIONS=	OPENSSL	"TLS/SSL support via openssl"	on \
		GNUTLS	"TLS/SSL support via gnutls"	off \
		IPV6	"IPv6 support"			on

.include <bsd.port.pre.mk>

.ifndef WITHOUT_OPENSSL
CONFIGURE_ARGS+=--enable-tls=openssl
.elifdef WITH_GNUTLS
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
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
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/admin/server.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/contrib/05to06.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/contrib/06to07.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/qa/fcgi.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/qa/run-tests.py	

post-install:
	@${INSTALL} -d ${CONFSUBDIRS:S|^|${PREFIX}/etc/cherokee/|}
	@for i in ${DEFCONFS};do\
		${INSTALL_DATA} ${WRKSRC}/$$i.sample ${PREFIX}/etc/cherokee/$$i.default;done
	@${INSTALL_DATA} ${WRKSRC}/performance.conf.sample ${PREFIX}/etc/cherokee/cherokee.conf.perf_sample
	@:>${PREFIX}/etc/cherokee/mods-enabled/.empty
	@:>${PREFIX}/etc/cherokee/sites-available/.empty
	@:>${PREFIX}/etc/cherokee/sites-enabled/.empty
	@:>${PREFIX}/etc/cherokee/ssl/.empty
	@for i in `${FIND} ${PREFIX}/etc/cherokee/ -name \*.default`;do\
		if [ ! -f $${i%.default} ];then ${CP} $$i $${i%.default};fi;done
	@for i in `${FIND} ${PREFIX}/etc/cherokee/ -name \*.sample`;do\
		if [ ! -f $${i%.sample} ];then ${CP} $$i $${i%.sample};fi;done

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
