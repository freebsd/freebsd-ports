# Created by: Juergen Lock <nox@FreeBSD.org>

PORTNAME=	vdr-plugin-markad
PORTVERSION=	0.1.4
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/1041/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - MarkAd plugin

LICENSE=	GPLv2+ LOGOS
LICENSE_COMB=	multi
LICENSE_NAME_LOGOS=	Station logos
LICENSE_TEXT_LOGOS=	Installs station logos
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_PERMS_LOGOS=	auto-accept

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang pkgconfig tar:tgz
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/command/Makefile ${WRKSRC}/plugin/Makefile
DEFINES=	-DDATADIR=\\\"${DATADIR}\\\" -DPREFIX=\\\"${PREFIX}\\\"
MAKE_ARGS=	DATADIR=${DATADIR} FREEBSD=1
MAKE_ENV=	DEFINES="${DEFINES}"

PORTDOCS=	README HISTORY
PORTDATA=	logos

OPTIONS_DEFINE=	DOCS NLS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

# for libexecinfo: (so that __builtin_frame_address() finds the top
# of the stack)
.if ${ARCH} == "amd64"
CFLAGS+=	-fno-omit-frame-pointer
CPPFLAGS+=	-fno-omit-frame-pointer
.endif

post-patch: post-patch-plugin
	@${LN} -s ../lib ../locale ${WRKSRC}

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
