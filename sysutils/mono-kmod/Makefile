# Created by: bkoenig@cs.tu-berlin.de
# $FreeBSD$

PORTNAME=	mono-kmod
PORTVERSION=	20070416
CATEGORIES=	sysutils kld
MASTER_SITES=	http://www.alpha-tierchen.de/pub/FreeBSD/ports/distfiles/

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Execute .NET applications from command line

ONLY_FOR_ARCHS=	i386 amd64 arm

SSP_UNSAFE=	kernel module does not support ssp
USE_BZIP2=	yes
KMODDIR?=	/boot/modules
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

SRC_BASE?=	/usr/src

PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

PLIST_FILES=	"@cwd %%KMODDIR%%"
PLIST_FILES+=	mono.ko
PLIST_FILES+=	"@unexec kldxref ${KMODDIR}"

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
