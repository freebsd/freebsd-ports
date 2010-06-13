# New ports collection makefile for:	biosfont
# Date created:				10 May 2006
# Whom:					Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	biosfont
PORTVERSION=	1.2
CATEGORIES=	sysutils kld
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory

LICENSE=	BSD

# only platforms guraranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	i386 amd64

MAN4=		biosfont.4

KMODDIR?=	/boot/modules

PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

.include <bsd.port.pre.mk>

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${PREFIX}/include
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
