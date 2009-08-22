# New ports collection makefile for:	dv2jpg
# Date created:				24 February 2003
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dv2jpg
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Type-2 DV codec-encoded AVI streams to mjpeg-encoded AVI

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv

USE_GNOME=	gdkpixbuf
MAKEFILE=	makefile

.if defined(WITH_PAL_VIDEO)
VID_FORMAT=	PAL
.else
VID_FORMAT=	NTSC
.endif

pre-everything::
	@${ECHO_MSG} "===> The default video format is NTSC"
	@${ECHO_MSG} "===> You can change this to PAL by defining"
	@${ECHO_MSG} "===> WITH_PAL_VIDEO"

post-extract:
	${RM} ${WRKSRC}/avijoin ${WRKSRC}/dv2jpg ${WRKSRC}/*.o

post-patch:
	@${REINPLACE_CMD} -e 's|%%VID_FORMAT%%|${VID_FORMAT}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avijoin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dv2jpg ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README.avilib	README.dv2jpg.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
