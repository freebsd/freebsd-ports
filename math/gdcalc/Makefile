# Created by: Jan Srocker <Jan.Stocker@t-online.de>
# $FreeBSD$
#    $MCom: ports/math/gdcalc/Makefile,v 1.1 2006/10/04 15:51:37 ahze Exp $

PORTNAME=	gdcalc
PORTVERSION=	2.15
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://bhepple.freeshell.org/dcalc/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome-based scientific calculator

RUN_DEPENDS=	${LOCALBASE}/bin/gunits:${PORTSDIR}/math/units

USES=		pkgconfig
USE_GNOME=	gnomehier libgnomeui
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
