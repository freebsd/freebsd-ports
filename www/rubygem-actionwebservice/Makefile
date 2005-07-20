# Ports collection makefile for:	rubygem-actionwebservice
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.net>)
#
# $FreeBSD$

PORTNAME=	actionwebservice
PORTVERSION=	0.7.1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/4155/

MAINTAINER=	jw@innerewut.net
COMMENT=	Simple support for publishing Web Service APIs for Rails applications

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/actionpack-1.8.1.gemspec:${PORTSDIR}/www/rubygem-actionpack
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
