PORTNAME=	television
DISTVERSION=	0.13.3
PORTREVISION=	1
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

PLIST_FILES=	bin/${PORTNAME} \
		bin/tv \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man1/tv.1.gz

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} tv ${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/tv.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/tv.1
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && \
		${LN} tv.1 television.1

.include <bsd.port.mk>
