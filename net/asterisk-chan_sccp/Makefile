# Created by: Diederik de Groot
# $FreeBSD$

PORTNAME=		chan_sccp
PORTVERSION=		4.2.3
PORTREVISION=		2
CATEGORIES=		net
MASTER_SITES=		SF/chan-sccp-b
PKGNAMEPREFIX=		asterisk-
DISTNAME=		Chan_SCCP-4.2.3_STABLE_r6728

MAINTAINER=		ddegroot@talon.nl
COMMENT=		Replacement for the SCCP channel driver in Asterisk

LICENSE=		GPLv1

BUILD_DEPENDS=		asterisk:net/asterisk13
RUN_DEPENDS=		asterisk:net/asterisk13

GNU_CONFIGURE=		yes
USES=			iconv compiler libtool
CONFIGURE_ARGS+=	--enable-video \
			--enable-video-layer \
			--enable-conference \
			--enable-advanced-functions \
			--with-hash-size=3001 \
			${ICONV_CONFIGURE_ARG}

CPPFLAGS+=		-I${ICONV_INCLUDE_PATH}
LDFLAGS+=		-L${LOCALBASE}/lib ${ICONV_LIB}

PLIST_FILES=		lib/asterisk/modules/chan_sccp.so \
			etc/asterisk/sccp.conf \
			etc/asterisk/sccp.conf.annotated

post-build:
	${STRIP_CMD} ${WRKSRC}/src/.libs/chan_sccp.so

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/asterisk
	(cd ${WRKSRC}/conf && ${CP} sccp.conf sccp.conf.annotated ${STAGEDIR}${PREFIX}/etc/asterisk/)

.include <bsd.port.mk>
