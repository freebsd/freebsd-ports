# New ports collection makefile for:	gpa
# Date created:		16 August 2000
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	gpa
PORTVERSION=	0.7.5
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/324/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical frontend for the GNU Privacy Guard

LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share
USE_GETOPT_LONG=	yes

.include <bsd.port.mk>
