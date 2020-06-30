# $FreeBSD$

PORTNAME=	securefs
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Filesystem in userspace with transparent encryption and decryption

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc \
		libjsoncpp.so:devel/jsoncpp

USES=		cmake fuse
LDFLAGS+=	-L${LOCALBASE}/lib -lutf8proc -ljsoncpp
USE_GITHUB=	yes
GH_ACCOUNT=	netheril96
PLIST_FILES=	bin/securefs

post-patch:
	${REINPLACE_CMD} "s|@GIT_VERSION@|${PORTVERSION}|" ${WRKSRC}/sources/git-version.cpp.in
	${MV} ${WRKSRC}/sources/git-version.cpp.in ${WRKSRC}/sources/git-version.cpp

.include <bsd.port.mk>
