# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library to make access to GnuPG easier

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-pth \
		--without-pth-test \
		--with-gpg=${LOCALBASE}/bin/gpg

INFO=	gpgme

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/gpgsm)
WITH_GPGSM=	yes
.endif

.if defined(WITH_GPGSM)
BUILD_DEPENDS+=	gpgsm:${PORTSDIR}/security/gnupg-devel
CONFIGURE_ARGS+=--with-gpgsm=${LOCALBASE}/bin/gpgsm
.else
CONFIGURE_ARGS+=	--without-gpgsm
.endif

.include <bsd.port.post.mk>
