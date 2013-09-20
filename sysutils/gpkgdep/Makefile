# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	gpkgdep
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Shows package dependencies in tree views

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_AUTOTOOLS=	automake14 autoconf
AUTOMAKE_ARGS=	--add-missing
USES=		gmake pkgconfig
PLIST_FILES=	bin/gpkgdep

NO_STAGE=	yes
.include <bsd.port.mk>
