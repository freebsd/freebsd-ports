# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	0.3.16
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme

MAINTAINER=	markun@onohara.to
COMMENT=	A library to make access to GnuPG easier

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	pth.20:${PORTSDIR}/devel/pth

LATEST_LINK=	gpgme03

USE_INC_LIBTOOL_VER=13
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
INSTALLS_SHLIB=	yes
USE_REINPLACE=	YES

INFO=	gpgme03

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gpgme03

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/gpgsm)
WITH_GPGSM=	yes
.endif

.if defined(WITH_GPGSM)
BUILD_DEPENDS+=	gpgsm:${PORTSDIR}/security/gnupg-devel
.else
CONFIGURE_ARGS+=	--without-gpgsm
.endif

post-patch:
.for i in tests tests/gpg tests/gpgsm
	@${REINPLACE_CMD} -e 's/libgpgme.la/libgpgme03.la/' \
		${WRKSRC}/${i}/Makefile.in
.endfor

.include <bsd.port.post.mk>
