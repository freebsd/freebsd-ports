# New ports collection makefile for:	ntalk
# Date created:			26 August 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	ntalk
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://kab.w.interia.pl/

MAINTAINER=	gslin@ccca.nctu.edu.tw

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	${PORTNAME}

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in AUTHORS COPYING ChangeLog INSTALL README
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
