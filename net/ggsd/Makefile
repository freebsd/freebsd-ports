# New ports collection makefile for:	ggsd
# Date created:				14 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	ggsd
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/
DISTNAME=	ggsd
EXTRACT_SUFX=	.tar

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Start a network server to execute scripts

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty

WRKSRC=		${WRKDIR}/GGSD

USE_GNOME=	gtk12

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ggsd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/example.scr ${DOCSDIR}
.endif

.include <bsd.port.mk>
