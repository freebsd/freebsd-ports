# New ports collection Makefile for:	kalgebra
# Date created:				5 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kalgebra
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 graph calculator

LIB_DEPENDS=	keduvocdocument.5:${PORTSDIR}/misc/libkdeedu

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl script scripttools xml \
		moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	READLINE "Install console interface" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_READLINE)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
PLIST_SUB+=	READLINE=""
.else
CMAKE_ARGS+=	-DWITH_Readline:BOOL=FALSE
PLIST_SUB+=	READLINE="@comment "
.endif

.include <bsd.port.mk>
