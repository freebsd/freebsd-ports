# Created by: bkoenig@cs.tu-berlin.de
# $FreeBSD$

PORTNAME=	mono-kmod
PORTVERSION=	20070416
CATEGORIES=	sysutils
MASTER_SITES=	http://www.alpha-tierchen.de/pub/FreeBSD/ports/distfiles/

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Execute .NET applications from command line

ONLY_FOR_ARCHS=	i386 amd64 arm

USE_BZIP2=	yes
SUB_FILES=	pkg-message

USES=		kmod uidfix

PLIST_FILES=	"@cwd /%%KMODDIR%%"
PLIST_FILES+=	mono.ko

.include <bsd.port.mk>
