# New ports collection makefile for:	Ruby/xmlconfigfile
# Date created:		25 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlconfigfile
PORTVERSION=	0.9.0
CATEGORIES=	textproc devel ruby
MASTER_SITES=	http://www.maik-schmidt.de/projects/xmlconfigfile/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module for easy handling of XML configuration files

USE_ZIP=	yes

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		docs CHANGES README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
