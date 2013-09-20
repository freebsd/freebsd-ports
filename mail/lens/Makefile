# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	lens
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.pitecan.com/Lens/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/lens|}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A mail filter written in Ruby

NO_BUILD=	yes
USE_RUBY=	yes

LIB_FILES=	lens.rb maildir.rb message.rb parsedate.rb classify.rb
RUBY_SHEBANG_FILES=	lens

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lens ${PREFIX}/bin
	${MKDIR} ${RUBY_SITELIBDIR}/lens
.for f in ${LIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}/lens
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lensrc.sample ${EXAMPLESDIR}/dot.lensrc
	${INSTALL_DATA} ${WRKSRC}/commandmailrc.sample ${EXAMPLESDIR}/dot.commandmailrc
.endif

.include <bsd.port.mk>
