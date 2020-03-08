# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	switzerland
PORTVERSION=	0.1.0
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/zero%20point%20one

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Test the integrity of communications over networks and firewalls

LICENSE=	GPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7 tar:tgz
USE_PYTHON=	distutils

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,gcc -O3,${CC} ${CFLAGS}, ; \
		s,"Switzerland","switzerland", ; \
		s,"0\.0","${PORTVERSION}",' ${WRKSRC}/setup.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS.txt ${WRKSRC}/README.txt \
		${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
