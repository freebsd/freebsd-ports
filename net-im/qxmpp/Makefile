# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qxmpp
PORTVERSION=	0.3.91
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	QXmpp is an xmpp client library based on Qt & C++

LICENSE=	LGPL21

USES=		qmake
USE_QT4=	gui network xml uic_build moc_build rcc_build

CONFLICTS=	${PORTNAME}-leechcraft-[0-9]*

pre-configure:
	${REINPLACE_CMD} -e 's|%%QT_LIBDIR_REL%%|${QT_LIBDIR_REL}|g' \
		${WRKSRC}/src/src.pro
	${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
