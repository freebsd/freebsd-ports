# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	switzerland
PORTVERSION=	0.1.0
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/zero%20point%20one
EXTRACT_SUFX=	.tgz

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Test the integrity of communications over networks and firewalls

LICENSE=	GPLv3

USES=		python
USE_PYTHON=	distutils

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,gcc -O3,${CC} ${CFLAGS}, ; \
		s,"Switzerland","switzerland", ; \
		s,"0\.0","${PORTVERSION}",' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS.txt ${WRKSRC}/README.txt \
		${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
