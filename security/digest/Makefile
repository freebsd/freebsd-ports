# New ports collection makefile for:	digest
# Date created:				2001-03-09
# Whom:					trevor
#
# $NetBSD: Makefile,v 1.4 2001/03/07 23:03:19 kim Exp $
# $FreeBSD$
#

PORTNAME=	digest
PORTVERSION=	20010807
PORTREVISION=	2
CATEGORIES=	security sysutils
MASTER_SITES=	#
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man/man
MAKE_ARGS=	VERSION="${PORTVERSION}"
MANCOMPRESSED=	yes
MAN1=		digest.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${FILESDIR} && pax -r -w * ${WRKSRC}

pre-install:
	${ECHO_CMD} bin/digest > ${PLIST}

.include <bsd.port.mk>
