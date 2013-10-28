# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

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

USE_XORG=	x11

DEPRECATED=	master site gone
EXPIRATION_DATE=	2013-12-31

NO_STAGE=	yes
post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/*.gz

.include <bsd.port.mk>
