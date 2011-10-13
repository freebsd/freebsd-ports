# New ports collection makefile for:	vdr-plugin-markad
# Date created:		Wed Mar 30 22:35:19 CEST 2011
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-markad
PORTVERSION=	0.1.2
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/578/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - MarkAd plugin

LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README
PORTDATA=	logos
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/command/Makefile ${WRKSRC}/plugin/Makefile
DEFINES+=	-DDATADIR=\\\"${DATADIR}\\\" -DPREFIX=\\\"${PREFIX}\\\"
MAKE_ARGS+=	DATADIR=${DATADIR} FREEBSD=1
MAKE_ENV+=	DEFINES="${DEFINES}"

RESTRICTED=	installs station logos

.include <bsd.port.pre.mk>

.include	"${.CURDIR}/../vdr/Makefile.plugins"

.if ${OSVERSION} < 800000
IGNORE=		needs getline(3)
.endif

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

.include <bsd.port.post.mk>
