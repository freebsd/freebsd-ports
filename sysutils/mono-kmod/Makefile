# Ports collection makefile for: mono-kmod
# Date created:		14 April 2007
# Whom:			bkoenig@cs.tu-berlin.de
#
# $FreeBSD$
#

PORTNAME=	mono-kmod
PORTVERSION=	20070416
CATEGORIES=	sysutils kld
MASTER_SITES=	http://www.alpha-tierchen.de/pub/FreeBSD/ports/distfiles/

MAINTAINER=	bkoenig@cs.tu-berlin.de
COMMENT=	Execute .NET applications from command line

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

USE_BZIP2=	yes
KMODDIR?=	/boot/modules
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

PLIST_FILES=	"@cwd %%KMODDIR%%"
PLIST_FILES+=	mono.ko

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
