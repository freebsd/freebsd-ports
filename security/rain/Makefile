# New ports collection makefile for:	rain
# Date created:				Sun Jul 29 10:25:08 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	rain
PORTVERSION=	1.2.7.b3
CATEGORIES=	security net
MASTER_SITES=	http://www.tenebrous.com/rain/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/7.b/7b/}

MAINTAINER=	pat@databits.net

GNU_CONFIGURE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rain ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES DISCLAIMER README TODO doc/EXAMPLES 
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
