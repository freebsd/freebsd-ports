# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qxmpp
PORTVERSION=	0.3.61
CATEGORIES=	net-im
MASTER_SITES=	http://cloud.github.com/downloads/0xd34df00d/qxmpp-dev/
PKGNAMESUFFIX=	-leechcraft
DISTNAME=	qxmpp-${PORTVERSION}-extras

MAINTAINER=	vg@FreeBSD.org
COMMENT=	XMPP client library based on C++ and Qt

LICENSE=	LGPL21

LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	gui moc_build network rcc_build uic_build xml

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|pkgconfig|../libdata/&|' \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -E 's|(docs\.commands\|INSTALLS)|#&|' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
