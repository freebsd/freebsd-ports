# New ports collection makefile for:	gpa
# Date created:		16 August 2000
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	gpa
PORTVERSION=	0.4.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

.include <bsd.port.mk>
