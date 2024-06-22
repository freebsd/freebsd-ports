PORTNAME=	LinearElasticity
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Elas, a solver for linear elasticity
WWW=		https://github.com/ISCDtoolbox/LinearElasticity

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libCommons.so:devel/iscd-commons

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	ISCDtoolbox

CFLAGS+=	-I${LOCALBASE}/include/ISCD
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README.md
PORTEXAMPLES=	*

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demos &&	\
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
