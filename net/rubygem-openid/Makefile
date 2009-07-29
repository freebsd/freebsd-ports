# New ports collection makefile for:	openid
# Date created:				Dec 19, 2006
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openid
PORTVERSION=	2.1.7
CATEGORIES=	net rubygems
MASTER_SITES=	http://www.openidenabled.com/files/ruby-openid/packages/ \
		RF
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An OpenID library written in pure Ruby

BUILD_DEPENDS=	rubygem-yadis>=0.3.4:${PORTSDIR}/net/rubygem-yadis
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
