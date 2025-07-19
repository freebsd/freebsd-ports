PORTNAME=	eza
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/eza-community/${PORTNAME}/releases/download/v${DISTVERSION}/man-${DISTVERSION}.tar.gz?dummy=/:man
DISTFILES=	${PORTNAME}-man-${DISTVERSION}.tar.gz:man

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern, maintained replacement for ls
WWW=		https://eza.rocks/

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	eza-community

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \
		share/man/man1/eza.1.gz \
		share/man/man5/eza_colors-explanation.5.gz \
		share/man/man5/eza_colors.5.gz \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/bash/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/target/man-${DISTVERSION}/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKDIR}/target/man-${DISTVERSION}/*.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
