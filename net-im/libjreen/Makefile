# New ports collection makefile for:	libjreen
# Date created:				2012-06-09
# Whom:					Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libjreen
PORTVERSION=	1.1.0
CATEGORIES=	net-im
MASTER_SITES=	http://qutim.org/downloads/

MAINTAINER=	akuz84@gmail.com
COMMENT=	Qt4 based jabber library

LICENSE=	GPLv2

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca \
		speex.1:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USE_QT4=	network moc_build qmake_build rcc_build uic_build
USE_CMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	${REINPLACE_CMD} -e 's,lib.*/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
