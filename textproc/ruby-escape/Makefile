PORTNAME=	escape
PORTVERSION=	0.2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.a-k-r.org/${PORTNAME}/ \
		LOCAL/tota/ruby-escape
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Ruby library provides HTML/URI/shell escaping functions

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/escape.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
