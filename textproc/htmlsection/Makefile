# New ports collection makefile for:	htmlsection
# Date created:		2 October 2001
# Whom:			SAKAI Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	htmlsection
PORTVERSION=	1.1
CATEGORIES=	textproc www
MASTER_SITES=	http://web.ffn.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	hsakai@m8.ffn.ne.jp
COMMENT=	Insert section numbers in HTML and make a table of contents

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
	@${MKDIR} ${PREFIX}/share/doc/ja/htmlsection
.for file in INSTALL-j README-j htmlsection-j_orig.html htmlsection-j.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ja/htmlsection
.endfor
.endif

.include <bsd.port.mk>
