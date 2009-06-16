# New ports collection makefile for:	Ruby/XML/Script
# Date created:		26 December 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xml-script
PORTVERSION=	0.2.0
CATEGORIES=	textproc ruby
MASTER_SITES=	http://gregoire.lejeune.free.fr/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby module for scripting an XML stream using an ASP-like notation

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/js.so:${PORTSDIR}/lang/ruby-js

USE_LUA=	4.0
LUA_COMPS=	ruby
USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

DOCS=		AUTHORS \
		README
EXAMPLES=	tests/*

post-patch:
	@${REINPLACE_CMD} -Ee 's|(language/lua)|\1-${LUA_VER}|' \
		${WRKSRC}/lib/xml/script/lua/compiler.rb

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
