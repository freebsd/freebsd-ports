# New ports collection makefile for:	Ruby-ASP
# Date created:		23 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	asp
PORTVERSION=	0.2.9
CATEGORIES=	www ruby
MASTER_SITES=	http://webtime-project.net/ruby-asp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An Active Server Pages port to Apache with Ruby scripting

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
