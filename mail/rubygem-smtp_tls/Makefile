# Ports collection makefile for:	rubygem-smtp_tls
# Date created:				25 July 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#
# NOTE that this gem is only required if you run Ruby 1.8.6
# SMTP TLS is built into Ruby 1.8.7+
#

PORTNAME=	smtp_tls
PORTVERSION=	1.0.3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Provides SMTP STARTTLS support for Ruby 1.8.6

RUN_DEPENDS=	rubygem-hoe>=2.3.2:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VERSION_CODE} >= 187000
IGNORE=	ruby >= 1.8.7 natively supports SMTP TLS
.endif

.include <bsd.port.post.mk>
