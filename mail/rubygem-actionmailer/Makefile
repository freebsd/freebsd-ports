# Ports collection makefile for:	gem-actionmailer
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.net>)
#
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	0.9.1
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/4152/

MAINTAINER=	jw@innerewut.net
COMMENT=	Easy email delivery and testing for Ruby

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/actionpack-1.8.1.gemspec:${PORTSDIR}/www/rubygem-actionpack
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
