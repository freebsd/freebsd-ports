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

MAINTAINER=	ruby@FreeBSD.org
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
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} ${DOCS} ${RUBY_MODDOCDIR}/)

	@${FIND} -ds ${RUBY_MODDOCDIR} -type f -print | ${SED} -E -e \
		's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${RUBY_MODDOCDIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/doc/ruby18/ 2>/dev/null || true" \
		>> ${TMPPLIST}
.endif

.include <bsd.port.mk>
