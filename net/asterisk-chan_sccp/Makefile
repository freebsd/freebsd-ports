# Created by: Diederik de Groot
# $FreeBSD$

PORTNAME=		chan_sccp
PORTVERSION=		4.2.3
CATEGORIES=		net
MASTER_SITES=		SF/chan-sccp-b
PKGNAMEPREFIX=		asterisk-
DISTNAME=		Chan_SCCP-4.2.3_STABLE_r6728

MAINTAINER=		ddegroot@talon.nl
COMMENT=		Replacement for the SCCP channel driver in Asterisk

LICENSE=		GPLv1

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

OPTIONS_SINGLE=		ASTVER
OPTIONS_SINGLE_ASTVER=	ASTERISK18 ASTERISK11 ASTERISK13
OPTIONS_DEFAULT=	ASTERISK13

ASTERISK18_DESC=	Depend on Asterisk 1.8
ASTERISK11_DESC=	Depend on Asterisk 11
ASTERISK13_DESC=	Depend on Asterisk 13

ASTERISK18_BUILD_DEPENDS=	asterisk:net/asterisk
ASTERISK18_RUN_DEPENDS=		asterisk:net/asterisk

ASTERISK11_BUILD_DEPENDS=	asterisk:net/asterisk11
ASTERISK11_RUN_DEPENDS=		asterisk:net/asterisk11

ASTERISK13_BUILD_DEPENDS=	asterisk:net/asterisk13
ASTERISK13_RUN_DEPENDS=		asterisk:net/asterisk13

post-build:
	${STRIP_CMD} ${WRKSRC}/src/.libs/chan_sccp.so

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/asterisk
	(cd ${WRKSRC}/conf && ${CP} sccp.conf sccp.conf.annotated ${STAGEDIR}${PREFIX}/etc/asterisk/)

.include <bsd.port.mk>
