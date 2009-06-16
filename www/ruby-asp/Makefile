# New ports collection makefile for:	Ruby-ASP
# Date created:		23 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	asp
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://gregoire.lejeune.free.fr/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An Active Server Pages port to Apache with Ruby scripting

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xslt_lib.so:${PORTSDIR}/textproc/ruby-xslt \
		${RUBY_SITELIBDIR}/xml/script.rb:${PORTSDIR}/textproc/ruby-xml-script

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

DOCS=		AUTHORS \
		README
EXAMPLES=	tests tests-cgi

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
