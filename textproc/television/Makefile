PORTNAME=	television
DISTVERSION=	0.13.3
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Fast and extensible general purpose fuzzy finder TUI
WWW=		https://github.com/alexpasmantier/television

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		bat:textproc/bat \
		fd:sysutils/fd \
		git:devel/git

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	alexpasmantier

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} tv ${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/tv.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/tv.1
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && \
		${LN} tv.1 television.1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/.config/config.toml ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/01-Users/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
