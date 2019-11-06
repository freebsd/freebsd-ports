# Created by: SAKAI Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	htmlsection
PORTVERSION=	1.1
CATEGORIES=	textproc www
MASTER_SITES=	http://web.ffn.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	hsakai@m8.ffn.ne.jp
COMMENT=	Insert section numbers in HTML and make a table of contents

BROKEN=		unfetchable

USES=		perl5
USE_PERL5=	build

JADOCSDIR=	share/doc/ja/${PORTNAME}
PLIST_SUB=	JADOCSDIR=${JADOCSDIR}

OPTIONS_DEFINE=	DOCS

pre-build:
		@(echo perl is set ${PERL} in pre-build:)
		@(cd ${WRKSRC}; ./findperl.sh ${PERL} > whereperl)
		@(cd ${WRKSRC}; ${CAT} whereperl)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlsection ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/htmlsection.1.gz ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in INSTALL README htmlsection_orig.html htmlsection.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${JADOCSDIR}
.for file in INSTALL-j README-j htmlsection-j_orig.html htmlsection-j.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/${JADOCSDIR}
.endfor

.include <bsd.port.mk>
