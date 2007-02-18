# Ports collection makefile for:	rubyfulsoup
# Date created:				16 feb 2007
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	rubyfulsoup
PORTVERSION=	1.0.4
CATEGORIES=	www textproc rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	rubyfulsoup
DISTNAME=	rubyful_soup-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby port of the HTML/XML parser Beautiful Soup

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/htmltools-1.10.gemspec:${PORTSDIR}/textproc/rubygem-htmltools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
