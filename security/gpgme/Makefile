# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	0.3.16
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme

MAINTAINER=	markun@onohara.to
COMMENT=	A library to make access to GnuPG easier

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	pth.20:${PORTSDIR}/devel/pth

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

INFO=	gpgme

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/gpgsm)
WITH_GPGSM=	yes
.endif

.if defined(WITH_GPGSM)
BUILD_DEPENDS+=	gpgsm:${PORTSDIR}/security/newpg
.else
CONFIGURE_ARGS+=	--without-gpgsm
.endif

.include <bsd.port.post.mk>
