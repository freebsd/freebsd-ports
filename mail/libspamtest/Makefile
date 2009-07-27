# New ports collection makefile for:    libspamtest
# Date created:				Fri 24 Jul 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$

PORTNAME=	libspamtest
PORTVERSION=	20080808
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Kaspersky Anti-Spam 3.x library

WRKSRC=		${WRKDIR}/libspamtest
MAKEFILE=	Makefile.FreeBSD

LIBS=		libspamtest.a \
		libspamtest_r.a
INCLUDES=	spamtest.h \
		msgstore.h

do-install:
	${MKDIR} ${PREFIX}/ap-mailfilter3/lib ${PREFIX}/ap-mailfilter3/include
	${INSTALL_DATA} ${LIBS:S,^,${WRKSRC}/,} ${PREFIX}/ap-mailfilter3/lib
	${INSTALL_DATA} ${INCLUDES:S,^,${WRKSRC}/,} \
		${PREFIX}/ap-mailfilter3/include

.include <bsd.port.mk>
