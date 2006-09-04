# New ports collection makefile for:	biosfont
# Date created:				10 May 2006
# Whom:					Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	biosfont
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://home.tiscali.nl/rladan/biosfont/

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory

# only platform guraranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	i386

MAN4=		biosfont.4

KMODDIR?=	/boot/modules

PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# patches for earlier versions are welcome
.if ${OSVERSION} < 502117
IGNORE=		requires FreeBSD 5.3 or higher
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${PREFIX}/include
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
