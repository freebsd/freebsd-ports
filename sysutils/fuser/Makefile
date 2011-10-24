# Ports collection makefile for:	fuser
# Date created:				14 Marth 2006
# Whom:					Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	fuser
PORTVERSION=	1142334561
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX fuser utility for FreeBSD

USE_BZIP2=	yes

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/fuser

MAN1=		fuser.1
PLIST_FILES=	bin/fuser

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900037
IGNORE=	fuser(1) utility is already present in the base system
.endif

.if (${OSVERSION} > 800000)
EXTRA_PATCHES+=	${FILESDIR}/extra::patch-fuser.c \
		${FILESDIR}/extra::patch-fuser.h
.endif
.if ${OSVERSION} >= 800066
EXTRA_PATCHES+=	${FILESDIR}/extra::patch-msdosfs.c
.endif
.if ${OSVERSION} >= 800101
EXTRA_PATCHES+=	${FILESDIR}/extra::patch-nfs.c
.endif
.if ${OSVERSION} >= 900000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch_ansify
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
