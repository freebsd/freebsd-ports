# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xmlconfigfile
PORTVERSION=	0.9.7
CATEGORIES=	textproc devel ruby
MASTER_SITES=	http://www.cs.ualberta.ca/~schofiel/xml-configfile/downloads/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	xml-configfile-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby module for easy handling of XML configuration files

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		docs CHANGES README TODO

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
