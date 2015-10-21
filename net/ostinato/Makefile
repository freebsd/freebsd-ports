# Created by: Niclas Zeising <zeising@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ostinato
PORTVERSION=	0.7.1
CATEGORIES=	net security
MASTER_SITES=	https://bintray.com/artifact/download/pstavirs/ostinato/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Packet crafter/generator and analyzer with friendly GUI

LICENSE=	GPLv3

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USES=		qmake
USE_QT4=	gui moc_build rcc_build uic_build network script \
		xml

PLIST_FILES=	bin/drone \
		bin/ostinato

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
