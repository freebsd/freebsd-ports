PORTNAME=	kubie
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Kubernetes context switching
WWW=		https://github.com/sbstp/kubie

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	Requires 64-bit processor

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sbstp

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish

.include <bsd.port.mk>
