PORTNAME=	kubie
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Kubernetes context switching
WWW=		https://github.com/sbstp/kubie

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	Requires 64-bit processor

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sbstp

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish

.include <bsd.port.mk>
