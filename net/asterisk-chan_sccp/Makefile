PORTNAME=	chan_sccp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.5.20231205
CATEGORIES=	net
PKGNAMEPREFIX=	asterisk-

MAINTAINER=	ddegroot@talon.nl
COMMENT=	Replacement for the SCCP channel driver in Asterisk
WWW=		https://sourceforge.net/projects/chan-sccp-b/

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

FLAVORS=	asterisk18 asterisk20 asterisk22
FLAVOR?=	${FLAVORS:[3]}

${FLAVOR}_PKGNAMEPREFIX=	${FLAVOR}-
${FLAVOR}_BUILD_DEPENDS=	asterisk:net/${FLAVOR}
${FLAVOR}_RUN_DEPENDS=		asterisk:net/${FLAVOR}

USES=		autoreconf:2.69 compiler:c11 gettext-tools iconv:wchar_t \
		libtool ssl
USE_GITHUB=	yes
GH_ACCOUNT=	chan-sccp
GH_PROJECT=	chan-sccp
GH_TAGNAME=	2e2105182824dc0ffda40f607290eb309d03a963

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-advanced-functions \
		--with-hash-size=3001
INSTALL_TARGET=	install-strip
CFLAGS+=	-D_ASTERISK_VERSION=${FLAVOR:C|([a-zA-Z]+)||}

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C|(.+)|\1-${PORTNAME}|}

PLIST_FILES=	etc/asterisk/sccp.conf.annotated \
		"@sample etc/asterisk/sccp.conf.sample" \
		lib/asterisk/modules/chan_sccp.so \
		share/asterisk/documentation/thirdparty/chan_sccp-en_US.xml

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
