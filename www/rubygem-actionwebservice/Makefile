# Ports collection makefile for:	rubygem-actionwebservice
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionwebservice
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5172/

MAINTAINER=	jw@innerewut.de
COMMENT=	Simple support for publishing Web Service APIs for Rails applications

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/actionpack-1.9.1.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.11.1.gemspec:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
