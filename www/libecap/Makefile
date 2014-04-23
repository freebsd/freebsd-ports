# Created by: Thomas-Martin Seck <tmseck@web.de>
# $FreeBSD$

PORTNAME=	libecap
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	www security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	tmseck@FreeBSD.org
COMMENT=	Library for module based network content analysis

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS

USES=		libtool:keepla

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	any
INSTALL_TARGET=	install-strip

PORTDOCS=	CREDITS LICENSE NOTICE README

CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
