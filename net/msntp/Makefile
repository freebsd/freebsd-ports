# New ports collection makefile for:	msntp
# Date created:				4 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	msntp
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.openpkg.org/sources/DST/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A straightforward SNTP daemon/utility

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="-lm"
CFLAGS+=	-DLOCKNAME='\"/var/run/msntp.pid\"'
CFLAGS+=	-DSAVENAME='\"/var/db/msntp.state\"'
MAN1=		msntp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msntp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/msntp.1 ${PREFIX}/man/man1
	${MKDIR} ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/Copyright ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
