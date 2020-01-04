# Created by: Diederik de Groot
# $FreeBSD$

PORTNAME=	chan_sccp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.2
DISTVERSIONSUFFIX=	-epsilon
PORTREVISION=	3
CATEGORIES=	net
PKGNAMEPREFIX=	asterisk-

MAINTAINER=	ddegroot@talon.nl
COMMENT=	Replacement for the SCCP channel driver in Asterisk

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	asterisk16 asterisk13
FLAVOR?=	${FLAVORS:[1]}

USES=		autoreconf compiler:c11 gettext-tools iconv libtool localbase

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

asterisk13_PKGNAMEPREFIX=	asterisk13-
asterisk13_CONFLICTS_INSTALL=	asterisk16-chan_sccp
asterisk13_BUILD_DEPENDS=	asterisk:net/asterisk13
asterisk13_RUN_DEPENDS=		asterisk:net/asterisk13

asterisk16_PKGNAMEPREFIX=	asterisk16-
asterisk16_CONFLICTS_INSTALL=	asterisk13-chan_sccp
asterisk16_BUILD_DEPENDS=	asterisk:net/asterisk16
asterisk16_RUN_DEPENDS=		asterisk:net/asterisk16

OPTIONS_DEFINE=			CONFERENCE VIDEO
OPTIONS_DEFAULT=		CONFERENCE VIDEO
CONFERENCE_DESC=		Enable Conference Support
VIDEO_DESC=			Enable Video Support

CONFERENCE_CONFIGURE_ENABLE=	conference
VIDEO_CONFIGURE_ENABLE=		video

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/asterisk
	${INSTALL_DATA} ${WRKSRC}/conf/sccp.conf \
		${STAGEDIR}${PREFIX}/etc/asterisk/sccp.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/sccp.conf.annotated \
		${STAGEDIR}${PREFIX}/etc/asterisk

.include <bsd.port.mk>
