# New ports collection makefile for:	yadis
# Date created:				Dec 19, 2006
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yadis
PORTVERSION=	0.3.4
CATEGORIES=	net rubygems
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/ruby-yadis/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Yadis Service discovery library written in pure Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}

post-install:
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -name "*~" -delete

.include <bsd.port.mk>
