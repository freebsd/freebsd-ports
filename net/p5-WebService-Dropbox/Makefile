# Created by: Lung-Pin Chang <changlp@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	WebService-Dropbox
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASKADNA
PKGNAMEPREFIX=	p5-

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Perl interface to Dropbox API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2.53:converters/p5-JSON \
		p5-Net-OAuth>=0.28:net/p5-Net-OAuth \
		p5-URI>=1.60:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	LWP
LWP_DESC=	Use LWP instead of Furl

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLWP}
BUILD_DEPENDS+=	p5-LWP-Protocol-https>=6.03:www/p5-LWP-Protocol-https \
		p5-libwww>=6.04:www/p5-libwww
RUN_DEPENDS+=	p5-LWP-Protocol-https>=6.03:www/p5-LWP-Protocol-https \
		p5-libwww>=6.04:www/p5-libwww
.else
BUILD_DEPENDS+=	p5-Furl>=1.01:www/p5-Furl \
		p5-IO-Socket-SSL>=1.77:security/p5-IO-Socket-SSL
RUN_DEPENDS+=	p5-Furl>=1.01:www/p5-Furl \
		p5-IO-Socket-SSL>=1.77:security/p5-IO-Socket-SSL
.endif

.include <bsd.port.mk>
