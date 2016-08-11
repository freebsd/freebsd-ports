# $FreeBSD$

PORTNAME=	libmediawiki
PORTVERSION=	4.12.0
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for accessing MediaWiki sites

USES=		pathfix
USE_LDCONFIG=	yes

.include "${.CURDIR:H:H}/graphics/digikam-kde4/Makefile.common"

# Replace some values set up by Makefile.common
DIGIKAM_VER=	${PORTVERSION}
DISTINFO_FILE=	${.CURDIR}/distinfo

.include <bsd.port.mk>
