# Ports collection makefile for:	gem-actionpack
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	1.9.1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5166/

MAINTAINER=	jw@innerewut.de
COMMENT=	Action Controller and Action View of Rails MVC Framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-1.1.1.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
