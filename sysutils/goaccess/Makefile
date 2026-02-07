PORTNAME=	goaccess
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://tar.goaccess.io/
PATCH_SITES=	https://github.com/allinurl/goaccess/commit/
PATCHFILES+=	fabd329.patch:-p1 8b37622.patch:-p1	# PR 2693
PATCHFILES+=	58219b2.patch:-p1			# PR 2739
PATCHFILES+=	edf8a85.patch:-p1			# PR 2801

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Real-time web log analyzer
WWW=		https://goaccess.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 pkgconfig ncurses
USE_RC_SUBR=	goaccess

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-utf8

CFLAGS+=	-I${NCURSESINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${NCURSESLIB} -L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README.md TODO

OPTIONS_DEFINE=	DOCS GEOIP2 NLS SSL
OPTIONS_DEFAULT=GEOIP2 SSL
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

GEOIP2_DESC=	IP location support
GEOIP2_CONFIGURE_ENABLE=geoip=mmdb
GEOIP2_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

SSL_DESC=	Use SSL for WebSocket
SSL_CONFIGURE_WITH=	openssl
SSL_USES=		ssl

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/goaccess.conf \
		${STAGEDIR}${ETCDIR}/goaccess.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
