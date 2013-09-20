# Created by: rene
# $FreeBSD$

PORTNAME=	biosfont
PORTVERSION=	1.2.1
CATEGORIES=	sysutils kld
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory

LICENSE=	BSD

SSP_UNSAFE=	kernel module does not support ssp

# only platforms guraranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	i386 amd64

MAN4=		biosfont.4

.include <bsd.port.pre.mk>

KMODDIR=	/boot/modules

PLIST_SUB=	KMODDIR=${KMODDIR} PREFIX=${PREFIX}
MAKE_ENV+=	KMODDIR=${KMODDIR}

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${PREFIX}/include
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
