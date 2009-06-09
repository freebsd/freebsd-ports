# New ports collection makefile for:	dclock
# Date created:		15 Aug 1996
# Whom:			David Leonard <leonard@dstc.edu.au>
#
# $FreeBSD$
#

PORTNAME=	dclock
PORTVERSION=	2.1.2.8
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/d/dclock
DISTNAME=	dclock_2.1.2.orig

PATCH_SITES=	${MASTER_SITE_DEBIAN:S,%SUBDIR%,pool/main/d/dclock,}
PATCHFILES=	dclock_2.1.2-8.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yasu@utahime.org
COMMENT=	A 7-segment digital clock with some optional features

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xt

WRKSRC=		${WRKDIR}/dclock
MAN1=		dclock.1

OPTIONS=	SOX "Install SoX to play audio" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SOX)
RUN_DEPENDS+=	play:${PORTSDIR}/audio/sox
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
				  -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
				  ${WRKSRC}/Dclock.c \
				  ${WRKSRC}/Dclock.ad \
				  ${WRKSRC}/dclock.1
	@${MV} ${WRKSRC}/dclock.1 ${WRKSRC}/dclock.man

post-install:
	${INSTALL_DATA} ${WRKSRC}/Dclock.ad ${PREFIX}/lib/X11/app-defaults/DClock
	${MKDIR} ${DATADIR}/sounds
.for f in bell.wav digital.wav
	${INSTALL_DATA} ${WRKSRC}/sounds/${f} ${DATADIR}/sounds
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DOCSDIR}/changelog.Debian
.endif

.include <bsd.port.post.mk>
