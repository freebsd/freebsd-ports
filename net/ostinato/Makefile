# Created by: Niclas Zeising <zeising@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ostinato
PORTVERSION=	0.8
PORTREVISION=	10
CATEGORIES=	net security
MASTER_SITES=	https://bintray.com/artifact/download/pstavirs/ostinato/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Packet crafter/generator and analyzer with friendly GUI

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		compiler:c++11-lang qmake qt:4
USE_CXXSTD=	c++11
USE_QT=		corelib gui moc_build rcc_build uic_build network script \
		xml

PLIST_FILES=	bin/drone \
		bin/ostinato

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
