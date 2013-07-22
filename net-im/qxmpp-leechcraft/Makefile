# New ports collection makefile for:	qxmpp-leechcraft
# Date created:				2012-01-07
# Whom:				Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qxmpp
PORTVERSION=	0.3.61
CATEGORIES=	net-im
MASTER_SITES=	http://cloud.github.com/downloads/0xd34df00d/qxmpp-dev/
PKGNAMESUFFIX=	-leechcraft
DISTNAME=	qxmpp-${PORTVERSION}-extras

MAINTAINER=	vg@FreeBSD.org
COMMENT=	XMPP client library based on C++ and Qt

LICENSE=	LGPL21

LIB_DEPENDS=	speex:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USE_QT4=	gui moc_build network qmake_build rcc_build uic_build xml

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|pkgconfig|../libdata/&|' \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -E 's|(docs\.commands\|INSTALLS)|#&|' \
		${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

.include <bsd.port.mk>
