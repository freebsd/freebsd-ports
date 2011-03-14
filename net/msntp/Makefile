# New ports collection makefile for:	msntp
# Date created:				4 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	msntp
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.openpkg.org/sources/DST/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A straightforward SNTP daemon/utility

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="-lm"
CFLAGS+=	-DLOCKNAME='\"/var/run/msntp.pid\"'
CFLAGS+=	-DSAVENAME='\"/var/db/msntp.state\"'
MAN1=		msntp.1
PORTDOCS=	README RFC2030.TXT
PLIST_FILES=	bin/msntp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msntp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/msntp.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
