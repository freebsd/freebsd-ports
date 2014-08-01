# $FreeBSD$

PORTNAME=	poudriere
PORTVERSION=	3.0.17
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://fossil.etoilebsd.net/poudriere/tarball/ \
		LOCAL/bdrewery/${PORTNAME}/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}?uuid=${PORTVERSION}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	ZSH
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	poudriere-devel

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/poudriere/*
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	@${INSTALL_DATA} ${WRKSRC}/zsh-completions \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_poudriere

.include <bsd.port.mk>
