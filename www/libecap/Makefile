# Created by: Thomas-Martin Seck <tmseck@web.de>
# $FreeBSD$

PORTNAME=	libecap
PORTVERSION=	1.0.0
CATEGORIES=	www security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for module based network content analysis

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

USES=		libtool

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	CREDITS LICENSE NOTICE README

CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
