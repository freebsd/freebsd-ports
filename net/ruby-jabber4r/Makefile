# New ports collection makefile for:	jabber4r
# Date created:		11 December 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jabber4r
PORTVERSION=	0.6.0
CATEGORIES=	net ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/376/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to connect to an existing Jabber account

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml
USE_RUBY_RDOC=		yes

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		LICENSE.txt README doc
EXAMPLES=	examples/*

.include <bsd.port.pre.mk>

PLIST_MODDOCDIR=	share/doc/${RUBY_NAME}/${RUBY_MODNAME}

post-extract:
	${RM} ${WRKSRC}/lib/jabber4r/LICENSE.txt

do-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC}
.endif

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	cd ${WRKSRC} && \
	${FIND} doc -type f|${SORT}| \
		${SED} 's:^:${PLIST_MODDOCDIR}/:' >> ${TMPPLIST}; \
	${FIND} doc -type d|${SORT} -r| \
		${SED} 's:^:@dirrm ${PLIST_MODDOCDIR}/:'>> ${TMPPLIST}
	${ECHO_CMD} '@dirrm ${PLIST_MODDOCDIR}'>> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
