# New ports collection makefile for:	kplayer
# Date created:				Fri Apr 11 09:12:55 CEST 2003
# Whom:					Stefan Eßer <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kplayer
PORTVERSION=	0.6.3
PORTREVISION=	5
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Movie player based on mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${SH} admin/cvs.sh dist)

.include <bsd.port.mk>
