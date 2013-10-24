# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	rdesktop
PORTVERSION=	1.7.1
PORTREVISION?=	1
CATEGORIES=	net comms ipv6
MASTER_SITES=	SF

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	RDP client for Windows NT/2000/2003 Terminal Server

LICENSE=	GPLv3

USE_XORG=	x11
USES=		gmake iconv
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
DOCS=		doc/AUTHORS doc/TODO doc/*.txt

OPTIONS_DEFINE=	DOCS IPV6 RDESKTOP_DEBUG SAMPLERATE AO
RDESKTOP_DEBUG_DESC=	Enable debugging

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libao.so) || ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	libao.so:${PORTSDIR}/audio/libao
.endif

.if exists(${LOCALBASE}/lib/libsamplerate.so) || ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if ${PORT_OPTIONS:MRDESKTOP_DEBUG}
CONFIGURE_ARGS+=	--with-debug\
			--with-debug-kbd\
			--with-debug-rdp5\
			--with-debug-clipboard\
			--with-debug-sound\
			--with-debug-channel\
			--with-debug-seamless

post-configure:
	${ECHO} "#define WITH_DEBUG_SERIAL 1" >> ${WRKSRC}/rdesktop.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdesktop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/rdesktop.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/keymaps
	${INSTALL_DATA} ${WRKSRC}/keymaps/* ${STAGEDIR}${DATADIR}/keymaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
