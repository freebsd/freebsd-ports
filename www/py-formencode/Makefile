# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	formencode
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormEncode-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	HTML form validation, generation, and conversion package

LICENSE=	PSFL

OPTIONS_DEFINE=	DOCS

USES=		gettext:run zip
USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
