# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	0.13.1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5175/

MAINTAINER=	jw@innerewut.de
COMMENT=	MVC web application framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/rake-0.5.4.gemspec:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/activesupport-1.1.1.gemspec:${PORTSDIR}/devel/rubygem-activesupport \
		${LOCALBASE}/${SPEC_DIR}/actionpack-1.9.1.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/actionwebservice-0.8.1.gemspec:${PORTSDIR}/www/rubygem-actionwebservice \
		${LOCALBASE}/${SPEC_DIR}/actionmailer-1.0.1.gemspec:${PORTSDIR}/mail/rubygem-actionmailer \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.11.1.gemspec:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
