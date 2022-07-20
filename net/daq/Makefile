PORTNAME=	daq
PORTVERSION=	2.2.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://snort.org/downloads/snortplus/ \
		ZI

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Data Acquisition abstraction library for snort 2.9+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libpcap.so.1:net/libpcap	# avoid base libpcap
BUILD_DEPENDS=	flex:textproc/flex

USES=		bison gmake libtool localbase
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	libdaq-3*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.* ${STAGEDIR}${PREFIX}/lib/daq/*.so

.include <bsd.port.mk>
