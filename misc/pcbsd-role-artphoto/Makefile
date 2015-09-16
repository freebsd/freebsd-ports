# New ports collection makefile for:	pcbsd-role-artphoto
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-artphoto
PORTVERSION=	1416510521
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes art and photography software

RUN_DEPENDS=	gimp>=0:${PORTSDIR}/graphics/gimp \
		fotoxx:${PORTSDIR}/graphics/fotoxx \
		darktable>=0:${PORTSDIR}/graphics/darktable \
		jalbum>=0:${PORTSDIR}/graphics/jalbum \
		xpaint>=0:${PORTSDIR}/graphics/xpaint

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
