# Created by: Niclas Zeising <zeising@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ostinato
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}${EXTRACTSUFFIX}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Packet crafter/generator and analyzer with friendly GUI

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USES=		qmake
USE_QT4=	gui moc_build rcc_build uic_build network script \
		xml

PLIST_FILES=	bin/drone \
		bin/ostinato

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
