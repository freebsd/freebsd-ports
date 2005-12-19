# Ports collection makefile for:	gem-actionmailer
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	1.1.5
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/7647/

MAINTAINER=	jw@innerewut.de
COMMENT=	Easy email delivery and testing for Ruby

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/actionpack-1.11.2.gemspec:${PORTSDIR}/www/rubygem-actionpack
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
