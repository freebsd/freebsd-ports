# New ports collection makefile for:	geheimnis
# Date created:		09 Feb 2001
# Whom:			Pekka Nikander <Pekka.Nikander@iki.fi>
#
# $FreeBSD$
#

PORTNAME=		geheimnis
PORTVERSION=		2.0.20021120
PORTREVISION=		2
CATEGORIES=		security kde
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"Shell for integrating PGP/GnuPG into KDE"

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/${PORTNAME}_kde3
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
