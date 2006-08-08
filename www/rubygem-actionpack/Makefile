# Ports collection makefile for:	gem-actionpack
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	1.12.1
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jw@innerewut.de
COMMENT=	Action Controller and Action View of Rails MVC Framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-1.3.1.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
