# Created by: Dean Freeman (wfreeman@sourcefire.com)
# $FreeBSD$

PORTNAME=	daq
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/snort/snort \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Data Acquisition abstraction library for snort 2.9+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet \
		libpcap.so:${PORTSDIR}/net/libpcap
BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		bison gmake libtool
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.* ${STAGEDIR}${PREFIX}/lib/daq/*.so

.if ${OSVERSION} < 901000
CONFIGURE_ARGS+=--disable-netmap-module
PLIST_SUB+=	NETMAP="@comment "
.else
PLIST_SUB+=	NETMAP=""
.endif

.include <bsd.port.post.mk>
