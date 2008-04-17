# New ports collection makefile for:   p5-Apache-ParseFormData
# Date created:                13-Jul-2004
# Whom:                        Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-ParseFormData
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nistor@snickers.org
COMMENT=	Module allows you to easily decode/parse form and query data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+	# mod_perl 2 requires it

MAN3=		Apache::ParseFormData.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
