PORTNAME=	vdr
DISTVERSION=	2.8.4
CATEGORIES=	multimedia

MAINTAINER=	sterum77@gmail.com
COMMENT=	Digital Video Recorder for DVB devices
WWW=		https://www.tvdr.de/ \
		https://www.linuxtv.org/vdrwiki/index.php/Main_Page

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	does not compile (time_t vs int overloading clash)

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype

USES=		gettext gmake iconv:wchar_t jpeg localbase:ldflags ncurses \
		perl5 pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	vdr-projects
USE_PERL5=	run
USE_RC_SUBR=	vdr
SHEBANG_FILES=	svdrpsend

LIBS+=		${ICONV_LIB}
MAKE_ARGS=	ARGSDIR=${ETCDIR}/conf.d \
		CONFDIR=${ETCDIR} \
		PCDIR=${PREFIX}/libdata/pkgconfig \
		VDR_USER=${VDR_USER} \
		VIDEODIR=${VIDEODIR}
ALL_TARGET=	vdr i18n plugins

SUB_FILES=	pkg-message vdr-waitdvb
SUB_LIST=	VDR_GROUP=${VDR_GROUP} \
		VDR_USER=${VDR_USER} \
		VIDEODIR=${VIDEODIR}

USERS=		${VDR_USER}
GROUPS=		${VDR_GROUP}

PLIST_SUB=	VDR_GROUP=${VDR_GROUP} \
		VDR_USER=${VDR_USER}

PORTDOCS=	HISTORY MANUAL README

OPTIONS_DEFINE=	DOCS

VDR_CONFFILES=	camresponses.conf channels.conf diseqc.conf \
		keymacros.conf scr.conf sources.conf svdrphosts.conf

VDR_GROUP=	vdr
VDR_USER=	vdr
VIDEODIR=	/video

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/plugins
.for f in ${VDR_CONFFILES}
	${MV} ${STAGEDIR}${ETCDIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${INSTALL_DATA} ${FILESDIR}/remote.conf ${STAGEDIR}${ETCDIR}/remote.conf.sample
	${INSTALL_SCRIPT} ${WRKDIR}/vdr-waitdvb ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vdr \
		${STAGEDIR}${PREFIX}/lib/vdr/*.so.*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
