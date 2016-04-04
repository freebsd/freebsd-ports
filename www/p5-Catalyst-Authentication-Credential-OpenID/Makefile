# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	Catalyst-Authentication-Credential-OpenID
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OpenID credential for Catalyst::Plugin::Authentication framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7:www/p5-Catalyst-Runtime \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Net-OpenID-Consumer>=1.03:net/p5-Net-OpenID-Consumer \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/Module::Install::AuthorTests/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
