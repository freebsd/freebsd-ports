# New ports collection makefile for:	glimpse
# http://webglimpse.org/
# Date created:		25 August 1996
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	glimpse
PORTVERSION=	4.12.6
CATEGORIES=	textproc databases
MASTER_SITES=	ftp://ftp.polito.it/pub/tools/unix/harvest/

MAINTAINER=	ports@freebsd.org
COMMENT=	Text search engine

NO_CDROM=	"Restrictive copyright (don't sell for profit)"
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -DISO_CHAR_SET=1"
MAN1=		glimpse.1 glimpseindex.1 glimpseserver.1 agrep.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

pre-configure:
	${RM} ${WRKSRC}/config.cache
	${CHMOD} ugo+x ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
	${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${PREFIX}/bin

.include <bsd.port.post.mk>
