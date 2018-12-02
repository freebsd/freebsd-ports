# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	doc
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake:no_configure qt-dist:4
NO_BUILD=	yes

EXTRACT_AFTER_ARGS=	'${DISTNAME}/doc'

DOCSDIR=	${PREFIX}/share/doc/qt4

EXTRA_PATCHES=	# empty

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	cd ${WRKSRC}/doc && \
	${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} && \
	${COPYTREE_SHARE} qch ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
