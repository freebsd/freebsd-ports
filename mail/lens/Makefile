# New ports collection makefile for:	Lens
# Date created:		2006-03-31
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	lens
PORTVERSION=	0.2
CATEGORIES=	mail ruby
MASTER_SITES=	http://pitecan.com/Lens/

MAINTAINER=	tota@rtfm.jp
COMMENT=	A mail filter written in Ruby

NO_BUILD=	yes
USE_RUBY=	yes

LIB_FILES=	lens.rb maildir.rb message.rb parsedate.rb classify.rb
RUBY_SHEBANG_FILES=	lens

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lens ${PREFIX}/bin
	@${MKDIR} ${RUBY_SITELIBDIR}/lens
.for f in ${LIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}/lens
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lensrc.sample ${EXAMPLESDIR}/dot.lensrc
	${INSTALL_DATA} ${WRKSRC}/commandmailrc.sample ${EXAMPLESDIR}/dot.commandmailrc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
