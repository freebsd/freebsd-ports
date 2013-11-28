# Created by: Sokolov Alexey <sokolov@TrueBSD.org>
# $FreeBSD$

PORTNAME=	qwit
DISTVERSION=	r154
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	qwit-${PORTVERSION}-src

MAINTAINER=	sokolov@TrueBSD.org
COMMENT=	Qt4-based lightweight Twitter client

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	gui network xml moc_build rcc_build \
		uic_build
post-patch:
	${REINPLACE_CMD} '/icon.path/s,share/icons,share/pixmaps,' \
		${WRKSRC}/qwit.pro

.include <bsd.port.mk>
