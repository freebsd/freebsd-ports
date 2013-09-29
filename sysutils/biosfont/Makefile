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

USES=		uidfix

.include <bsd.port.pre.mk>

KMODDIR=	/boot/modules

PLIST_SUB=	KMODDIR=${KMODDIR} PREFIX=${PREFIX}
MAKE_ENV+=	KMODDIR=${KMODDIR} NO_XREF=yes

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

pre-install:
	${MKDIR} ${STAGEDIR}/boot/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/biosfont.4 ${STAGEDIR}${PREFIX}/man/man4

.include <bsd.port.post.mk>
