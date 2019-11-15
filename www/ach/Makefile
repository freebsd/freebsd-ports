# Created by: Carlo Strub <c-s@c-s.li>
# $FreeBSD$

PORTNAME=	ACH
PORTVERSION=	1.0.3
DISTVERSIONSUFFIX=	-alpha
CATEGORIES=	www
MASTER_SITES=	GHC

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free, open source tool for complex research problems

BROKEN=		unfetchable

LICENSE=	GPLv3

USES=		mysql php tar
USE_GITHUB=	yes
GH_ACCOUNT=	Burton
GH_PROJECT=	Analysis-of-Competing-Hypotheses

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
SUB_FILES+=	pkg-message
WWWDIR?=	${PREFIX}/www/${PORTNAME}

# Get rid of temp files packaged in the upstream distfile
post-extract:
	@${FIND} ${WRKSRC} -type f -not -name .htaccess -a \
		-name .\* -delete

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
