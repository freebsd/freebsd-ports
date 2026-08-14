PORTNAME=	go-away
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	www security
MASTER_SITES=	https://git.gammaspectra.live/git/${PORTNAME}/archive/
DISTFILES=	${DISTVERSIONFULL}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Proxy implementing countermeasures for unwanted LLM training
WWW=		https://git.gammaspectra.live/git/go-away

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	go_away

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

SUB_LIST=	DEFAULT_USER="www"

GO_MODULE=	git.gammaspectra.live/git/go-away
GO_MOD_DIST=	https://git.gammaspectra.live/git/${PORTNAME}/raw/tag/${DISTVERSIONFULL}/
GO_TARGET=	./cmd/go-away

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/go-away

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${EXAMPLESDIR}/snippets
	${INSTALL_DATA} ${WRKSRC}/examples/*.yml ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/snippets/* \
		${STAGEDIR}${EXAMPLESDIR}/snippets

.include <bsd.port.mk>
