PORTNAME=	mathml-xsd
PORTVERSION=	2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/Math/XMLSchema/
DISTNAME=	mathml${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MathML XML Schema

USES=		tar:tgz
NO_BUILD=	yes
PORTDATA=	*

post-extract:
	@${FIND} ${WRKSRC} -name "CVS" -type d -exec rm -rf {} +;
	@${RM} ${WRKSRC}/content/tokens.xsd.~1.3.~

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
