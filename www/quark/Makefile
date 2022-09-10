PORTNAME=	quark
DISTVERSION=	g20210222
CATEGORIES=	www
MASTER_SITES=	LOCAL/tobik
PKGNAMESUFFIX=	-server
DISTNAME=	quark-68b4f733b2755762e43df90f73db5a6ec8d14104

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and simple HTTP GET/HEAD-only web server for static content
WWW=		https://tools.suckless.org/quark/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	quark

PLIST_FILES=	bin/quark \
		share/man/man1/quark.1.gz

pre-everything::
	@${ECHO_MSG} "You can build quark with your own config.h using the QUARK_CONF knob:"
	@${ECHO_MSG} "make QUARK_CONF=/path/to/quark/config.h install clean"

.if defined(QUARK_CONF)
post-patch:
	@${ECHO_MSG} "Creating config.h from ${QUARK_CONF}"
	@${LN} -sf ${QUARK_CONF} ${WRKSRC}/config.h
.endif

do-configure:
	@${ECHO_CMD} PREFIX="${PREFIX}" >>${WRKSRC}/config.mk
	@${ECHO_CMD} CC="${CC}" >>${WRKSRC}/config.mk
	@${ECHO_CMD} CFLAGS+="${CFLAGS}" >>${WRKSRC}/config.mk
	@${ECHO_CMD} LDFLAGS+="${LDFLAGS}" >>${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quark

.include <bsd.port.mk>
