# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xml-configfile
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	textproc devel ruby
MASTER_SITES=	http://www.cs.ualberta.ca/~schofiel/${PORTNAME}/downloads/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module for easy handling of XML configuration files

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		CHANGES README TODO docs/index.html

DEPRECATED=	Upstream no longer exists
EXPIRATION_DATE=	2017-01-28

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
