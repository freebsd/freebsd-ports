# New ports collection makefile for:	kplayer
# Date created:				Fri Apr 11 09:12:55 CEST 2003
# Whom:					Stefan Eßer <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kplayer
PORTVERSION=	0.6.3
PORTREVISION=	7
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Movie player based on mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

PORTSCOUT=	limit:^0\.6\.

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	automake:env autoconf:env libtool

AUTOTOOLSFILES=	admin/cvs.sh

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${SH} admin/cvs.sh dist)

.include <bsd.port.mk>
