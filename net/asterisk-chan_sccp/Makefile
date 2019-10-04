# Created by: Diederik de Groot
# $FreeBSD$

PORTNAME=	chan_sccp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gamma
CATEGORIES=	net
PKGNAMEPREFIX=	asterisk-

MAINTAINER=	ddegroot@talon.nl
COMMENT=	Replacement for the SCCP channel driver in Asterisk

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext-tools iconv libtool
USE_GITHUB=	yes
GH_ACCOUNT=	chan-sccp
GH_PROJECT=	chan-sccp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-advanced-functions \
		--with-hash-size=3001 \
		${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${ICONV_INCLUDE_PATH}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${ICONV_LIB}

PLIST_FILES=	etc/asterisk/sccp.conf.annotated \
		"@sample etc/asterisk/sccp.conf.sample" \
		lib/asterisk/modules/chan_sccp.so \
		share/asterisk/documentation/thirdparty/chan_sccp-en_US.xml

OPTIONS_DEFINE=		CONFERENCE VIDEO
OPTIONS_DEFAULT=	AST16 CONFERENCE VIDEO
OPTIONS_SINGLE=		ASTVER
OPTIONS_SINGLE_ASTVER=	AST13 AST16

ASTVER_DESC=		Which asterisk to build for
AST13_DESC=		Asterisk 13
AST16_DESC=		Asterisk 16
CONFERENCE_DESC=	Enable Conference Support
VIDEO_DESC=		Enable Video Support

AST13_BUILD_DEPENDS=	asterisk13>0:net/asterisk13
AST13_RUN_DEPENDS=	asterisk13>0:net/asterisk13

AST16_BUILD_DEPENDS=	asterisk16>0:net/asterisk16
AST16_RUN_DEPENDS=	asterisk16>0:net/asterisk16

CONFERENCE_CONFIGURE_ENABLE=	conference
VIDEO_CONFIGURE_ENABLE=		video

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/asterisk
	${INSTALL_DATA} ${WRKSRC}/conf/sccp.conf \
		${STAGEDIR}${PREFIX}/etc/asterisk/sccp.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/sccp.conf.annotated \
		${STAGEDIR}${PREFIX}/etc/asterisk

.include <bsd.port.mk>
