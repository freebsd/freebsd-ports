# New ports collection makefile for:	www/p5-Data-Validate-URI
# Date created:				02 January 2008
# Whom:					Tuc <freebsd-ports@t-b-o-h.net>
#
# $FreeBSD$
#

PORTNAME=	Data-Validate-URI
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@t-b-o-h.net
COMMENT=	Common data validation methods for URIs

BUILD_DEPENDS=	${SITE_PERL}/Data/Validate/Domain.pm:${PORTSDIR}/dns/p5-Data-Validate-Domain \
		${SITE_PERL}/Data/Validate/IP.pm:${PORTSDIR}/net-mgmt/p5-Data-Validate-IP
RUN_DEPENDS=	${SITE_PERL}/Data/Validate/Domain.pm:${PORTSDIR}/dns/p5-Data-Validate-Domain \
		${SITE_PERL}/Data/Validate/IP.pm:${PORTSDIR}/net-mgmt/p5-Data-Validate-IP

PERL_CONFIGURE=	yes

MAN3=	Data::Validate::URI.3

.include <bsd.port.mk>
