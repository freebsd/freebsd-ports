# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	doc
DISTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework

USE_QT4=	# empty
QT_DIST=	yes
NO_BUILD=	yes

EXTRACT_AFTER_ARGS=	'${DISTNAME}/doc'

DOCSDIR=	${PREFIX}/share/doc/qt4

NO_STAGE=	yes
do-install:
	${MKDIR} ${DOCSDIR} && \
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR} && \
	${COPYTREE_SHARE} qch ${DOCSDIR}

.include <bsd.port.mk>
