# New ports collection makefile for:	Ruby/XML/Script
# Date created:		26 December 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xml-script
PORTVERSION=	0.1.0
CATEGORIES=	textproc ruby
MASTER_SITES=	http://gregoire.lejeune.free.fr/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module for scripting an XML stream using an ASP-like notation

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/js.so:${PORTSDIR}/lang/ruby-js \
		${RUBY_SITEARCHLIBDIR}/lua.so:${PORTSDIR}/lang/ruby-lua4

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

DOCS=		AUTHORS \
		README
EXAMPLES=	tests/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
