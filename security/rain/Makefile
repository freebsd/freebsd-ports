# New ports collection makefile for:	rain
# Date created:				Sun Jul 29 10:25:08 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	rain
PORTVERSION=	1.2.9.b1
CATEGORIES=	security net
MASTER_SITES=	http://rain.tenebrous.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	pat@FreeBSD.org

GNU_CONFIGURE=	yes

MANCOMPRESSED=	yes
MAN1=		${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rain ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1.gz \
		${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES DISCLAIMER README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
