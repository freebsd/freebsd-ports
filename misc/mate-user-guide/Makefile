# Created by: Eric Turgeon <ericbsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-user-guide
PORTVERSION=	1.22.3
CATEGORIES=	misc mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE users guide

LICENSE=	GFDL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		intltool>=0.40.0:textproc/intltool
RUN_DEPENDS=	yelp:x11/yelp

PORTSCOUT=	limitw:1,even

USES=		gettext gmake tar:xz
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
