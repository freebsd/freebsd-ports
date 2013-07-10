# Created by: Juergen Lock <nox@freebsd.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-markad
PORTVERSION=	0.1.4
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/1041/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - MarkAd plugin

LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		execinfo:${PORTSDIR}/devel/libexecinfo

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
PORTDATA=	logos
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/command/Makefile ${WRKSRC}/plugin/Makefile
DEFINES+=	-DDATADIR=\\\"${DATADIR}\\\" -DPREFIX=\\\"${PREFIX}\\\"
MAKE_ARGS+=	DATADIR=${DATADIR} FREEBSD=1
MAKE_ENV+=	DEFINES="${DEFINES}"
MANCOMPRESSED=	yes
MAN1=		markad.1

RESTRICTED=	installs station logos

.include	"${.CURDIR}/../vdr/Makefile.plugins"

# for libexecinfo: (so that __builtin_frame_address() finds the top
# of the stack)
.if ${ARCH} == "amd64"
CFLAGS+=	-fno-omit-frame-pointer
CPPFLAGS+=	-fno-omit-frame-pointer
.endif

post-patch: post-patch-plugin
	@${LN} -s ../lib ../locale ${WRKSRC}

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
