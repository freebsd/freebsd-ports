# Created by: vanilla@
# $FreeBSD$

PORTNAME=	xqilla
PORTVERSION=	2.3.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	XQilla-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	XQuery and XPath2 library

OPTIONS_DEFINE=	DOCS

LICENSE=	APACHE20

LIB_DEPENDS=	libxerces-c.so.3:${PORTSDIR}/textproc/xerces-c3

USES=		gmake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen

post-build:
	cd ${WRKSRC} && ${GMAKE} docs

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \*-api ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
