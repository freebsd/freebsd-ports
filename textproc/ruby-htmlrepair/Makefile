# New ports collection makefile for:	htmlrepair.rb
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	htmlrepair
PORTVERSION=	1.0.1
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to repair unclosed tags in an HTML document

RUN_DEPENDS=	${RUBY_SITELIBDIR}/htmlsplit.rb:${PORTSDIR}/textproc/ruby-htmlsplit

PLIST_FILES=	%%RUBY_SITELIBDIR%%/htmlrepair.rb
USE_ZIP=	yes
USE_RUBY=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlrepair.rb ${RUBY_SITELIBDIR}/

.include <bsd.port.mk>
