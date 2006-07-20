# New ports collection makefile for:	ruby-xmpp4r
# Date created:				21 Nov 2005
# Whom:					Stephan Maka <stephan@spaceboyz.net>
#
# $FreeBSD$
#

PORTNAME=	xmpp4r
PORTVERSION=	0.3
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
DOCS=		ChangeLog LICENSE README UPDATING
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
	${CP} -R ${WRKSRC}/rdoc/ ${RUBY_MODDOCDIR}/rdoc
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/${f}/
	${CP} -R ${WRKSRC}/data/doc/xmpp4r/examples/${f}/ ${RUBY_MODEXAMPLESDIR}/${f}/
.endfor
.endif

.include <bsd.port.mk>
