# New ports collection makefile for:	gpa
# Date created:		16 August 2000
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	gpa
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/gpa

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical frontend for the GNU Privacy Guard

BUILD_DEPENDS=	gpgme-config:${PORTSDIR}/security/gpgme \
		gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share
USE_GETOPT_LONG=	yes

.include <bsd.port.mk>
