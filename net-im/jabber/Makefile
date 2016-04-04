# Created by: joe
# $FreeBSD$

PORTNAME=	jabber
PORTVERSION=	1.6.1.1
PORTREVISION=	19
PORTEPOCH=	1
CATEGORIES=	net-im ipv6
MASTER_SITES=	http://download.jabberd.org/jabberd14/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	jabberd14-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMPP/Jabber server daemon

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt \
		libpth.so:devel/pth-hard \
		libidn.so:dns/libidn \
		libgnutls.so:security/gnutls \
		libexpat.so:textproc/expat2

OPTIONS_DEFINE= IPV6 MYSQL PGSQL DOCS

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake iconv libtool pkgconfig
USE_RC_SUBR=	jabber
CONFIGURE_ARGS=	--localstatedir=/var \
		--sysconfdir=${JABBER_ETCDIR} \
		--includedir=${PREFIX}/include/jabber \
		--libdir=${PREFIX}/lib/jabber
USE_LDCONFIG=	${PREFIX}/lib/jabber
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	$$(pth-config --cflags) \
		-I${LOCALBASE}/include
LDFLAGS+=	$$(pth-config --ldflags) \
		-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
SUB_LIST=	JABBER_USER=${JABBER_USER} \
		JABBER_GROUP=${JABBER_GROUP} \
		JABBER_ETCDIR="${JABBER_ETCDIR}" \
		JABBER_LOGDIR="${JABBER_LOGDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}" \
		JABBER_RUNDIR="${JABBER_RUNDIR}"
PLIST_SUB=	JABBER_USER=${JABBER_USER} \
		JABBER_GROUP=${JABBER_GROUP} \
		JABBER_LOGDIR="${JABBER_LOGDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}" \
		JABBER_RUNDIR="${JABBER_RUNDIR}"

USERS=		${JABBER_USER}
GROUPS=		${JABBER_GROUP}

JABBER_USER=	jabber
JABBER_GROUP=	jabber
JABBER_ETCDIR=	${PREFIX}/etc
JABBER_RUNDIR=	/var/run/jabberd
JABBER_SPOOLDIR=/var/spool/jabberd
JABBER_LOGDIR=	/var/log/jabberd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if exists(${LOCALBASE}/include/pth/pthread.h)
IGNORE=	pth with soft syscalls is installed, please reinstall pth from devel/pth-hard
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|\\\$$(localstatedir)/log/jabberd|${JABBER_LOGDIR}|g ; \
		 s|\\\$$(localstatedir)/spool/jabberd|${JABBER_SPOOLDIR}| ; \
		 s|\\\$$(localstatedir)/run/jabberd|${JABBER_RUNDIR}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@localstatedir@/log/jabberd|${JABBER_LOGDIR}|g ; \
		 s|@localstatedir@/spool/jabberd|${JABBER_SPOOLDIR}|g ; \
		 s|@localstatedir@/run/jabberd|${JABBER_RUNDIR}|g' \
		${WRKSRC}/jabber.xml.dist.in
	@${REINPLACE_CMD} -e \
		'/<gcrypt.h>/s|^|//| ; \
		 /gcry_control/s|^|//|' \
		${WRKSRC}/jabberd/gcrypt_init.c
	@${REINPLACE_CMD} -e \
		's|locale, LOCALEDIR)|locale)|' \
		${WRKSRC}/jabberd/lib/messages.cc
	@${REINPLACE_CMD} -e \
		's|"$(localedir)|"$$(DESTDIR)$(localedir)|' \
		${WRKSRC}/po/Makefile.in
	@${LN} -s jabberd.8.in ${WRKSRC}/man/jabberd14.8.in

post-install:
	@${TOUCH} ${STAGEDIR}${PREFIX}/include/jabber/platform-settings
	(cd ${WRKSRC} && ${INSTALL_DATA} jabber.xml.dist \
		${STAGEDIR}${PREFIX}/etc/jabber.xml.sample)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog INSTALL NEWS README README.SQL README.config \
	README.filespool README.karma README.protocols TODO UPGRADE mysql.sql
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
