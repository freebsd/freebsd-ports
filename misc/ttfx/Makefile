PORTNAME=	ttfx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	misc

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Terminal text effects, a Rust port of terminaltexteffects
WWW=		https://github.com/omacom/ttfx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	omacom

PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --print-completion bash > \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --print-completion zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
