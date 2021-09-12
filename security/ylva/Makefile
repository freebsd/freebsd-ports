PORTNAME=	ylva
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line password manager and file encryption program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libqrcodegen.so:graphics/qr-code-generator

USES=		gmake localbase:ldflags sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	nrosvall

WRKSRC_SUBDIR=	src

MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME} share/man/man1/ylva.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
