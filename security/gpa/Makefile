# New ports collection makefile for:	gpa
# Date created:		16 August 2000
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	gpa
PORTVERSION=	0.7.6
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/350/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical frontend for the GNU Privacy Guard

LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

.include <bsd.port.mk>
