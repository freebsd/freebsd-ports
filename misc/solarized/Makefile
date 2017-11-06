# $FreeBSD$

PORTNAME=	solarized
PORTVERSION=	1.0.0
CATEGORIES=	misc
MASTER_SITES=	http://ethanschoonover.com/solarized/files/
DISTNAME=	${PORTNAME}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Precision colors schemes for machines and people

LICENSE=	MIT

USES=		zip
NO_BUILD=	yes

do-install:
	${RM} ${WRKSRC}/vim-colors-solarized/doc/.DS_Store
	${RM} ${WRKSRC}/vim-colors-solarized/colors/.DS_Store
	${RM} ${WRKSRC}/vim-colors-solarized/colors/.solarized.vim.un~
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
