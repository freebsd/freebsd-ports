# Created by: ijliao
# $FreeBSD$

PORTNAME=	mathml-xsd
PORTVERSION=	2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/Math/XMLSchema/
DISTNAME=	mathml${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MathML XML Schema

NO_BUILD=	yes

post-extract:
	@${FIND} ${WRKSRC} -name "CVS" -type d -exec rm -rf {} +;
	@${RM} ${WRKSRC}/content/tokens.xsd.~1.3.~

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
