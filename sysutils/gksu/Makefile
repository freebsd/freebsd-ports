# New ports collection makefile for:   gksu
# Date created:        2 October 2004
# Whom:                Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
#
# $FreeBSD$
#

PORTNAME=	gksu
PORTVERSION=	1.3.7
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/gksu/

MAINTAINER=	bsam@ipt.ru
COMMENT=	Graphical frontend to su

LIB_DEPENDS=	gksu1.2.0:${PORTSDIR}/sysutils/libgksu \
		gksuui1.0.1:${PORTSDIR}/sysutils/libgksuui \
		gnome-keyring.0:${PORTSDIR}/security/gnomekeyring

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 pkgconfig gnomeprefix gnomehack gconf2 intlhack
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gksu.schemas
MAN1=		gksu.1 gksuexec.1
MLINKS=		gksu.1 gksudo.1

.include <bsd.port.mk>
