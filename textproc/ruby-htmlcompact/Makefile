# New ports collection makefile for:	htmlcompact.rb
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	htmlcompact
PORTVERSION=	1.0.2
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to compact an HTML document by reducing whitespaces

RUN_DEPENDS=	${RUBY_SITELIBDIR}/htmlsplit.rb:${PORTSDIR}/textproc/ruby-htmlsplit

PLIST_FILES=	%%RUBY_SITELIBDIR%%/htmlcompact.rb
USE_BZIP2=	yes
USE_RUBY=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlcompact.rb ${RUBY_SITELIBDIR}/

.include <bsd.port.mk>
