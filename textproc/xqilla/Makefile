# Created by: vanilla@
# $FreeBSD$

PORTNAME=	xqilla
PORTVERSION=	2.3.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	XQilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XQuery and XPath2 library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxerces-c.so.3:${PORTSDIR}/textproc/xerces-c3

USES=		gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
PORTDOCS=	*
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
    		dot:${PORTSDIR}/graphics/graphviz

post-build:
	cd ${WRKSRC} && ${MAKE_CMD} docs

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \*-api ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
