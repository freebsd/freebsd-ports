# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	3.2.19
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-mail25>=2.5.4:${PORTSDIR}/mail/rubygem-mail25

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
