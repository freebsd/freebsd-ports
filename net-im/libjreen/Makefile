# $FreeBSD$

PORTNAME=	libjreen
PORTVERSION=	1.1.1
CATEGORIES=	net-im

MAINTAINER=	akuz84@gmail.com
COMMENT=	Qt4 based jabber library

LICENSE=	GPLv2

LIB_DEPENDS=	qca:${PORTSDIR}/devel/qca \
		speex:${PORTSDIR}/audio/speex

GH_ACCOUNT=	euroelessar
GH_COMMIT=	388621f
GH_PROJECT=	jreen
GH_TAGNAME=	v${PORTVERSION}

LDFLAGS+=	-L${LOCALBASE}/lib


USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT4=	moc_build qmake_build rcc_build network

USES=		cmake pkgconfig:build

NO_STAGE=	yes
pre-configure:
	${REINPLACE_CMD} -e 's,lib.*/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
