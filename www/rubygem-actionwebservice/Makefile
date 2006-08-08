# Ports collection makefile for:	rubygem-actionwebservice
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionwebservice
PORTVERSION=	1.1.2
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	aws

MAINTAINER=	jw@innerewut.de
COMMENT=	Simple support for publishing Web Service APIs for Rails applications

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/actionpack-1.12.1.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.14.2.gemspec:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
