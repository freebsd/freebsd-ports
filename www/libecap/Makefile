# Ports collection Makefile for: libecap
# Date created:			2009/06/02
# Whom:				Thomas-Martin Seck <tmseck@web.de>
#
# $FreeBSD$
#

PORTNAME=	libecap
PORTVERSION=	0.0.2
CATEGORIES=	www security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	tmseck@web.de
COMMENT=	Library for module based network content analysis

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	4.2+

PORTDOCS=	CREDITS LICENSE NOTICE README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
