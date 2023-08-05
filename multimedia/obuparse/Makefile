PORTNAME=	obuparse
DISTVERSION=	g20230712
CATEGORIES=	multimedia

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Simple and portable single file AV1 OBU parser
WWW=		https://github.com/dwbuiten/obuparse

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	dwbuiten
GH_TAGNAME=	f40598f

USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

INSTALL_TARGET=	install-shared

PLIST_FILES=	include/obuparse.h \
		lib/libobuparse.so \
		lib/libobuparse.so.1

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libobuparse.so.1

.include <bsd.port.mk>
