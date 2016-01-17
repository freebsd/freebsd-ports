# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	htree
PORTVERSION=	0.8
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.a-k-r.org/htree/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby library to manipulate HTML/XML tree data structure

OPTIONS_DEFINE=	DOCS

USE_RUBY=	yes
USE_RUBY_RDOC=		yes

LIB_FILES=	htree.rb htree

DOCS=		README \
		${RUBY_RD_HTML_FILES} \
		doc
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*

.include <bsd.port.options.mk>

do-build:
.if ${PORT_OPTIONS:MDOCS}
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC} ${LIB_FILES}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	cd ${INSTALL_WRKSRC}; ${CP} -R ${LIB_FILES} ${STAGEDIR}${RUBY_SITELIBDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
