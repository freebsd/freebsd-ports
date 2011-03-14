# New ports collection makefile for:	ntalk
# Date created:			26 August 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	ntalk
PORTVERSION=	0.6.3
CATEGORIES=	net
MASTER_SITES=	http://network.terramail.pl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A console chat application written with ncurse

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

do-build:
	cd ${WRKSRC}; \
	${CXX} ${CXXFLAGS} -o ntalk ntalk.cpp -lncurses ${PTHREAD_LIBS}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in AUTHORS COPYING ChangeLog INSTALL README
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
