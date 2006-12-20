# New ports collection makefile for:	openid
# Date created:				Dec 19, 2006
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openid
PORTVERSION=	1.1.3
CATEGORIES=	net rubygems
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/ruby-openid/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Yadis Service discovery library written in pure Ruby

BUILD_DEPENDS=	rubygem-yadis>=0.3.3:${PORTSDIR}/net/rubygem-yadis
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
GEM_NAME=	${DISTNAME}

post-install:
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -name "*~" -delete

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
