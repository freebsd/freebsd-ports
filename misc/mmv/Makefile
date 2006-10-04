# New ports collection makefile for:	mmv
# Date created:		2 Feb 1995
# Whom:			Michael Elbel (me)
#
# $FreeBSD$
#

PORTNAME=	mmv
PORTVERSION=	1.01b.14
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_1.01b.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_1.01b-14.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	simon@olofsson.de
COMMENT=	Move/Copy/Append/Link multiple files

CFLAGS+=	-DHAS_DIRENT
MAN1=		mmv.1
PLIST_FILES=	bin/mmv
WRKSRC=		${WRKDIR}/${PORTNAME}-1.01b.orig

do-build:
	@(cd ${WRKSRC} ; \
	${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c ; )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/mmv.1 ${PREFIX}/man/man1/mmv.1

.include <bsd.port.mk>
