# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	doc
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework

QT_DIST=	yes
NO_BUILD=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

EXTRACT_AFTER_ARGS=| ${TAR} -xf - '${DISTNAME}/doc'

DOCSDIR=${PREFIX}/share/doc/qt4

do-install:
	${MKDIR} ${DOCSDIR} && \
	${CP} -Rp ${WRKSRC}/doc/html ${WRKSRC}/doc/qch ${DOCSDIR}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../Mk/bsd.qt.mk"
.include <bsd.port.post.mk>
