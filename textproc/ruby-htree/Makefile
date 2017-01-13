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

LIB_FILES=	htree.rb htree

DOCS=		README \
		doc
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*

.include <bsd.port.options.mk>

do-build:
.if ${PORT_OPTIONS:MDOCS}
	cd ${BUILD_WRKSRC}; ${LOCALBASE}/bin/rdoc${RUBY_SUFFIX} ${LIB_FILES}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	cd ${INSTALL_WRKSRC}; ${CP} -R ${LIB_FILES} ${STAGEDIR}${RUBY_SITELIBDIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
