# Created by: Nick Hilliard <nick@foobar.org
# $FreeBSD$

PORTNAME=	Apache2-SiteControl
PORTVERSION=	1.05
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nick@foobar.org
COMMENT=	Perl web site authentication/authorization system

BUILD_DEPENDS=	p5-Apache-AuthCookie>=3.08:www/p5-Apache-AuthCookie \
		p5-Apache-Session>=1.54:www/p5-Apache-Session \
		p5-Crypt-CAST5>=0.04:security/p5-Crypt-CAST5 \
		p5-Crypt-CBC>=2.14:security/p5-Crypt-CBC \
		p5-libapreq2>=2.05:www/p5-libapreq2
RUN_DEPENDS=	p5-Apache-AuthCookie>=3.08:www/p5-Apache-AuthCookie \
		p5-Apache-Session>=1.54:www/p5-Apache-Session \
		p5-Crypt-CAST5>=0.04:security/p5-Crypt-CAST5 \
		p5-Crypt-CBC>=2.14:security/p5-Crypt-CBC \
		p5-libapreq2>=2.05:www/p5-libapreq2

OPTIONS_DEFINE=		RADIUS
OPTIONS_DEFAULT=	RADIUS

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MRADIUS}
RUN_DEPENDS+=	p5-Authen-Radius>=0.10:security/p5-Authen-Radius
.endif

.include <bsd.port.mk>
