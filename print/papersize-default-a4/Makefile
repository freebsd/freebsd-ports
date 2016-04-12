# Created by: hrs
# $FreeBSD$

PORTNAME=	papersize-default
PORTVERSION=	0.0.20120302
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	# none
PKGNAMESUFFIX=	-${DEFAULTPAPERSIZE:tl}
DISTFILES=	# none

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Default paper size configuration file for libpaper

LIB_DEPENDS=	libpaper.so:print/libpaper

NO_BUILD=	yes

DEFAULTPAPERSIZE?=	a4
.for P in a4 letter
.if ${DEFAULTPAPERSIZE:tl:M${P}} != ${P}
CONFLICTS_INSTALL+=	papersize-default-${P}-[0-9]*
.endif
.endfor

PLIST_FILES=	etc/papersize

do-install:
	${LN} -s -f papersize.${DEFAULTPAPERSIZE:tl} \
		${STAGEDIR}${PREFIX}/etc/papersize

.include <bsd.port.mk>
