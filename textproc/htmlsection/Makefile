# New ports collection makefile for:	htmlsection
# Date created:		2 October 2001
# Whom:			SAKAI Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	htmlsection
PORTVERSION=	1.0
CATEGORIES=	textproc www
MASTER_SITES=	http://www.seki.ee.kagu.tus.ac.jp/~sakai/myfreesoft/ \
		http://hp.vector.co.jp/authors/VA014157/myfreesoft/ \
		http://www.people.or.jp/~hsakai/myfreesoft/

MAINTAINER=	sakai@seki.ee.kagu.tus.ac.jp

MAN1=		htmlsection.1
MANCOMPRESSED=	yes

pre-build:
		@(echo perl is set ${PERL} in pre-build:)
		@(cd ${WRKSRC}; ./findperl.sh ${PERL} > whereperl)
		@(cd ${WRKSRC}; ${CAT} whereperl)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlsection ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/htmlsection.1.gz ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in INSTALL README htmlsection_orig.html htmlsection.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
