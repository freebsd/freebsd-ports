# New ports collection makefile for:   hiawatha
# Date created:        24 november 2006
# Whom:                Hugo Leisink <hugo@leisink.net>
#
# $FreeBSD$
#

PORTNAME=	hiawatha
PORTVERSION=	8.3.2
CATEGORIES=	www
MASTER_SITES=	http://www.hiawatha-webserver.org/files/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	An advanced and secure webserver for Unix

LICENSE=	GPLv2

PORTDOCS=	AUTHORS ChangeLog INSTALL
CONFIG_FILES=	hiawatha.conf mimetype.conf cgi-wrapper.conf php-fcgi.conf \
		toolkit.conf index.xslt

MAN1=		cgi-wrapper.1 hiawatha.1 php-fcgi.1 ssi-cgi.1 wigwam.1

MAKE_JOBS_SAFE=	yes
SUB_FILES=	pkg-message
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	hiawatha php-fcgi
WANT_GNOME=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR=${PREFIX}/bin \
		-DCMAKE_INSTALL_SBINDIR=${PREFIX}/sbin \
		-DCMAKE_INSTALL_SYSCONFDIR=${ETCDIR} \
		-DCMAKE_INSTALL_LIBDIR=${PREFIX}/lib \
		-DCONFIG_DIR=${ETCDIR} \
		-DWEBROOT_DIR=${WWWDIR} \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DLOG_DIR=/var/log/hiawatha \
		-DPID_DIR=/var/run

OPTIONS=	CACHE "Enable cache support" On \
		CHROOT "Enable chroot support" Off \
		COMMAND "Enable the Hiawatha CommandChannel" Off \
		DEBUG "Enable debug information (for development only)" Off \
		IPV6 "Enable IPv6 support" On \
		MONITOR "Enable Hiawatha Monitor" Off \
		RPROXY "Enable Reverse Proxy" On \
		SSL "Enable SSL support" On \
		TOOLKIT "Enable the URL toolkit" On \
		XSLT "Enable XSLT support" On

PLIST_SUB+=	ECHO_MSG=${ECHO_MSG}

.include <bsd.port.pre.mk>

.if !defined(WITH_CACHE)
CMAKE_ARGS+=	-DENABLE_CACHE=off
.endif

.if defined(WITH_CHROOT)
CMAKE_ARGS+=	-DENABLE_CHROOT=on
.endif

.if defined(WITH_COMMAND)
CMAKE_ARGS+=	-DENABLE_COMMAND=on
.endif

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DENABLE_DEBUG=on
.endif

.if !defined(WITH_IPV6)
CMAKE_ARGS+=	-DENABLE_IPV6=off
.endif

.if defined(WITH_MONITOR)
CMAKE_ARGS+=	-DENABLE_MONITOR=on
.endif

.if !defined(WITH_RPROXY)
CMAKE_ARGS+=	-DENABLE_RPROXY=off
.endif

.if !defined(WITH_SSL)
CMAKE_ARGS+=	-DENABLE_SSL=off
.endif

.if !defined(WITH_TOOLKIT)
CMAKE_ARGS+=	-DENABLE_TOOLKIT=off
.endif

.if defined(WITH_XSLT)
CMAKE_ARGS+=	-DENABLE_XSLT=on
USE_GNOME+=	libxslt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in \
	${WRKSRC}/man/php-fcgi.1.in ${WRKSRC}/config/cgi-wrapper.conf \
	${WRKSRC}/config/hiawatha.conf.in ${WRKSRC}/config/php-fcgi.conf.in

	@${REINPLACE_CMD} -e 's|/etc/hiawatha|${ETCDIR}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in \
	${WRKSRC}/man/php-fcgi.1.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.for FILE in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/config/${FILE} ${PREFIX}/etc/hiawatha/${FILE}.sample
	@if [ ! -f ${PREFIX}/etc/hiawatha/${FILE} ]; then \
		${CP} -p ${WRKSRC}/config/${FILE} ${PREFIX}/etc/hiawatha/${FILE} ; \
	fi
.endfor

	@if [ ! -d ${WWWDIR} ]; then \
		@${MKDIR} ${WWWDIR} ; \
	fi
	@${CP} ${WRKSRC}/extra/index.html ${WWWDIR}/index.hiawatha.html
	@if [ ! -f ${WWWDIR}/index.html ] ; then \
		${CP} ${WRKSRC}/extra/index.html ${WWWDIR}/ ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
