# New ports collection makefile for:	ruby-xmpp4r
# Date created:				21 Nov 2005
# Whom:					Stephan Maka <stephan@spaceboyz.net>
#
# $FreeBSD$
#

PORTNAME=	xmpp4r
PORTVERSION=	0.2
CATEGORIES=	net-im ruby
MASTER_SITES=	http://download.gna.org/xmpp4r/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	stephan@spaceboyz.net
COMMENT=	XMPP/Jabber library for Ruby

USE_RUBY=	YES
USE_RUBY_RDOC=	YES

LIB_FILES=	lib/xmpp4r.rb lib/callbacks.rb lib/xmpp4r
DOCS=		ChangeLog LICENSE README
EXAMPLES=	basic advanced

do-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC} \
		-o rdoc \
		--all --fileboxes --inline-source --line-numbers \
		${LIB_FILES}
.endif

do-install:
	cd ${INSTALL_WRKSRC}; ${CP} -R ${LIB_FILES} ${RUBY_SITELIBDIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${CP} -R ${WRKSRC}/rdoc/ ${RUBY_MODDOCDIR}/
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/data/doc/xmpp4r/examples/${f}/ ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
