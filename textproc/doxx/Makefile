PORTNAME=	doxx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	textproc

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Docx files in your terminal
WWW=		https://github.com/bgreenwell/doxx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bgreenwell

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
