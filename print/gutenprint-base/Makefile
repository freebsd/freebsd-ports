# ports collection makefile for: gimp-print
# Date Created: 2002 01 02
# Whom: dgilbert@velocet.ca

# $FreeBSD$

PORTNAME=	gimp-print
PORTVERSION=	4.2.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dgilbert@velocet.ca

RUN_DEPENDS=	gimp:${PORTSDIR}/graphics/gimp1
LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cups --with-ghost
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	escputil.1 gimpprint-config.1
MAN3=	gimpprint.3
MAN8=	cups-calibrate.8

.include <bsd.port.mk>
