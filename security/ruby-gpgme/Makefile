# New ports collection makefile for:	Ruby-GPGME
# Date created:		29 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security ruby
MASTER_SITES=	http://deisui.org/~ueno/ruby/ruby-gpgme/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to GnuPG Made Easy (GPGME)

LIB_DEPENDS=	gpgme03.9:${PORTSDIR}/security/gpgme03

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=	yes

INSTALL_TARGET=	site-install

DOCS=		doc
EXAMPLES=	examples/*

post-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC} lib
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
