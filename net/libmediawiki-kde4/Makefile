# $FreeBSD$

PORTNAME=	libmediawiki
PORTVERSION=	4.12.0
PORTREVISION=	3
CATEGORIES=	net kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for accessing MediaWiki sites

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

PORTSCOUT=	limit:^4\.12\.

USES=		pathfix
USE_LDCONFIG=	yes

.include "${.CURDIR:H:H}/graphics/digikam-kde4/Makefile.common"

# Replace some values set up by Makefile.common
DIGIKAM_VER=	${PORTVERSION}
DISTINFO_FILE=	${.CURDIR}/distinfo

.include <bsd.port.mk>
