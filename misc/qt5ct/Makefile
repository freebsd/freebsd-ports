# $FreeBSD$

PORTNAME=	qt5ct
PORTVERSION=	0.25
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt 5 configuration tool

LICENSE=	BSD2CLAUSE

USES=		qmake tar:bz2
USE_QT5=	core gui svg widgets buildtools_build linguisttools_build
USE_GL=	gl

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR} && \
	${INSTALL_DATA}	${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
