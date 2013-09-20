# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	searchmonkey
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/Searchmonkey2/${PORTVERSION}%20%5Bstable%5D
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search using regexes for file names and text

LICENSE=	GPLv3 # (or later)

USE_ZIP=	yes
USE_DOS2UNIX=	*.cpp *.h
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${PORTNAME}_2_0.pro \
		${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)

.include <bsd.port.mk>
