PORTNAME=	monaspace
DISTVERSION=	1.400
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/githubnext/monaspace/releases/download/v${DISTVERSION}/
DISTFILES=	${PORTNAME}-static-v${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-variable-v${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Innovative superfamily of fonts for code
WWW=		https://monaspace.githubnext.com

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

	@cd ${WRKSRC}/"Static Fonts" && ${FIND} . -name '*.otf' | while read f; do \
		${INSTALL_DATA} "$$f" ${STAGEDIR}${FONTSDIR}; \
	done

	@cd ${WRKSRC}/"Variable Fonts" && ${FIND} . -name '*.ttf' | while read f; do \
		${INSTALL_DATA} "$$f" \
			${STAGEDIR}${FONTSDIR}/`${BASENAME} "$$f" | ${TR} -d ' '`; \
	done

	${LS} ${STAGEDIR}${FONTSDIR}/*.otf ${STAGEDIR}${FONTSDIR}/*.ttf | \
		${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
