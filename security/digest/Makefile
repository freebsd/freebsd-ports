# New ports collection makefile for:	digest
# Date created:				2001-03-09
# Whom:					trevor
#
# $NetBSD: Makefile,v 1.4 2001/03/07 23:03:19 kim Exp $
# $FreeBSD$
#

PORTNAME=	digest
PORTVERSION=	20010302
CATEGORIES=	security sysutils
MASTER_SITES=	#
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org

CFLAGS+=	"-DVERSION=${PORTVERSION}"
MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man
MAN1=		digest.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${FILESDIR} && pax -r -w * ${WRKSRC}

pre-install:
	${ECHO} bin/digest > ${PLIST}

post-install:
	${INSTALL_MAN} ${FILESDIR}/digest.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
