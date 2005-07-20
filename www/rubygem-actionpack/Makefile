# Ports collection makefile for:	gem-actionpack
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.net>)
#
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	1.8.1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/4149/

MAINTAINER=	jw@innerewut.net
COMMENT=	Action Controller and Action View of Rails MVC Framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-1.0.4.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
