# New ports collection makefile for:	Ruby-TMail
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tmail
PORTVERSION=	0.10.8
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A RFC2822/MIME compliant mail manipulating library for Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	racc-runtime

DOCS_EN=	Incompatibilities	README.en	doc.en/*	\
		*ChangeLog		BUGS		TODO
DOCS_JA=	Incompatibilities.ja	README.ja	doc.ja/*

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/ ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
