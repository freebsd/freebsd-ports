# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	twill
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://darcs.idyll.org/~t/projects/

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Simple scripting language for Web browsing

BROKEN=		unfetchable

USES=		python:2.7
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
