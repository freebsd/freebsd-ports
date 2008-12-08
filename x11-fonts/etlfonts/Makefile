# New ports collection makefile for:	etlfonts-noncjk
# Date created:		3 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	etlfonts-noncjk
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	# disappeared
DISTNAME=	non-cjk
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 supplemental fonts

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
USE_XORG=	x11

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/*.gz

post-install:
	@${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.mk>
