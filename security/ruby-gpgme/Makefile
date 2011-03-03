# New ports collection makefile for:	Ruby-GPGME
# Date created:		29 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	1.0.8
CATEGORIES=	security ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby-gpgme
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby interface to GnuPG Made Easy (GPGME)

LIB_DEPENDS=	gpgme.18:${PORTSDIR}/security/gpgme

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=	yes

INSTALL_TARGET=	site-install

DOCS=		doc
EXAMPLES=	examples/*

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

post-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC} lib
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} ${DOCS} ${RUBY_MODDOCDIR}/)

	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	@${FIND} -ds ${RUBY_MODDOCDIR} -type f -print | ${SED} -E -e \
		's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${RUBY_MODDOCDIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/doc/ruby18/ 2>/dev/null || true" \
		>> ${TMPPLIST}
.endif

.include <bsd.port.mk>
