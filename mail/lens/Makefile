# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	lens
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.pitecan.com/Lens/ \
		LOCAL/tota/lens

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Mail filter written in Ruby

NO_BUILD=	yes
BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes
USE_RUBY=	yes
USES=		shebangfix

LIB_FILES=	lens.rb maildir.rb message.rb parsedate.rb classify.rb
SHEBANG_FILES=	lens

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lens ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/lens
.for f in ${LIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_SITELIBDIR}/lens
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lensrc.sample ${STAGEDIR}${EXAMPLESDIR}/dot.lensrc
	${INSTALL_DATA} ${WRKSRC}/commandmailrc.sample ${STAGEDIR}${EXAMPLESDIR}/dot.commandmailrc

.include <bsd.port.mk>
