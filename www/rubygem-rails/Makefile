# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.net>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	0.12.1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/4158/

MAINTAINER=	jw@innerewut.net
COMMENT=	MVC web application framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/rake-0.5.4.gemspec:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/activesupport-1.0.4.gemspec:${PORTSDIR}/devel/rubygem-activesupport \
		${LOCALBASE}/${SPEC_DIR}/actionpack-1.8.1.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/actionwebservice-0.7.1.gemspec:${PORTSDIR}/www/rubygem-actionwebservice \
		${LOCALBASE}/${SPEC_DIR}/actionmailer-0.9.1.gemspec:${PORTSDIR}/mail/rubygem-actionmailer \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.10.1.gemspec:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
