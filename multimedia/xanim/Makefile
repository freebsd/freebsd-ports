# New ports collection makefile for:	xanim
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $FreeBSD$
#

PORTNAME=       xanim
PORTVERSION=	2.80.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://xanim.va.pubnix.com/ \
		ftp://xanim.va.pubnix.com/dlls/
DISTNAME=       xanim2801
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}

MAINTAINER=	ports@FreeBSD.org

EXTRA_FILES=    vid_cvid_2.1_freebsdELFx86.tgz \
		vid_cyuv_1.0_freebsdELFx86.tgz \
		vid_h261_1.0_freebsdELFx86.tgz \
		vid_h263_1.0_freebsdELFx86.tgz \
		vid_iv32_2.1_freebsdELFx86.tgz \
		vid_iv41_1.1_freebsdELFx86.tgz \
		vid_iv50_1.0_freebsdELFx86.tgz
USE_IMAKE=	yes
MAN1=		xanim.1

DLLDIR=		${PREFIX}/lib/X11/xanim

post-extract:
	${CP} ${WRKSRC}/docs/xanim.man ${WRKSRC}

post-install:
	@${MKDIR} ${DLLDIR}
	${INSTALL_DATA} ${WRKDIR}/*.readme ${DLLDIR}
	${INSTALL_DATA} ${WRKDIR}/*.xa ${DLLDIR}

.include <bsd.port.mk>
