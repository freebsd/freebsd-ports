# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	0.3.14
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	markun@onohara.to

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	pth.14:${PORTSDIR}/devel/pth

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-gpgsm
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

pre-configure:
	@${RM} -r ${WRKSRC}/doc/gpgme.info*

.include <bsd.port.mk>
