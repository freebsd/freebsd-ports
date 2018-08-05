# $FreeBSD$

PORTNAME=	castxml
PORTVERSION=	g20180728
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C-family Abstract Syntax Tree XML Output

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_10=	plist mismatch: extra items are installed for some reason

BUILD_DEPENDS=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	CastXML
GH_PROJECT=	CastXML
GH_TAGNAME=	a345f62
LLVM_VERSION=	60

CMAKE_ARGS=	-DLLVM_DIR:STRING=${LOCALBASE}/llvm${LLVM_VERSION}/lib/cmake/llvm

.include <bsd.port.mk>
