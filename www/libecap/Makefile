# Ports collection Makefile for: libecap
# Date created:			2009/06/02
# Whom:				Thomas-Martin Seck <tmseck@web.de>
#
# $FreeBSD$
#

PORTNAME=	libecap
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	tmseck@FreeBSD.org
COMMENT=	Library for module based network content analysis

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	4.2+

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	CREDITS LICENSE NOTICE README

CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
