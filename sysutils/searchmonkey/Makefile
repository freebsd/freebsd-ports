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

LICENSE=	GPLv3+

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake dos2unix qt:4 zip
USE_CXXSTD=	c++98
DOS2UNIX_GLOB=	*.cpp *.h
USE_QT=		corelib gui moc_build rcc_build uic_build

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
