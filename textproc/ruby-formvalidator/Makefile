# New ports collection makefile for:	FormValidator for Ruby
# Date created:		21 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	formvalidator
PORTVERSION=	0.1.4
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://grub.ath.cx/formvalidator/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module to validate data coming in from HTML forms

USE_RUBY=	yes
USE_RUBY_RDOC=		yes

DOCS=		AUTHORS \
		CHANGELOG \
		README \
		TODO \
		doc

do-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC} --main README.rdoc formvalidator.rb README.rdoc
.endif

do-install:
	cd ${INSTALL_WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
