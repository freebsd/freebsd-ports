# Created by: Jan Srocker <Jan.Stocker@t-online.de>
# $FreeBSD$

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

LDFLAGS+=	-lm

NO_STAGE=	yes
.include <bsd.port.mk>
