# New ports collection makefile for:	tlswrap
# Date created:		25 July 2005
# Whom:			Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	tlswrap
PORTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	http://tlswrap.sunsite.dk/
DISTNAME=	${PORTNAME}-1.02

MAINTAINER=	darius@dons.net.au
COMMENT=	An FTP proxy that wraps data and control with TLS/SSL

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/tlswrap
PORTDOCS=	README

.include <bsd.port.pre.mk>

post-configure:
.if ( ${OSVERSION} < 500000 )
	@${REINPLACE_CMD} -E 's,#define socklen_t size_t,,g' \
		${WRKSRC}/conf.h
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS|LDFLAGS).*=,\1?=,g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
