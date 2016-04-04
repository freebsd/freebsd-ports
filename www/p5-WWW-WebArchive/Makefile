# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WWW-WebArchive
PORTVERSION=	0.50
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Retrieve old versions of public web pages from various web archives

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Options>=0:devel/p5-App-Options \
		p5-App-Trace>=0:devel/p5-App-Trace \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|WWW-WebArchive|WWW::WebArchive|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
