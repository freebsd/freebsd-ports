# Created by: Dean Freeman (wfreeman@sourcefire.com)
# $FreeBSD$

PORTNAME=	daq
PORTVERSION=	2.0.6
CATEGORIES=	net
MASTER_SITES=	https://snort.org/downloads/snort/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Data Acquisition abstraction library for snort 2.9+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libpcap.so:net/libpcap
BUILD_DEPENDS=	flex:textproc/flex

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		bison gmake libtool
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.* ${STAGEDIR}${PREFIX}/lib/daq/*.so

.include <bsd.port.mk>
