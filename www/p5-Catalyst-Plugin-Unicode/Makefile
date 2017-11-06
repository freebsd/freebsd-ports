# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Unicode
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Unicode aware Catalyst

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0.10:devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-Test-WWW-Mechanize-Catalyst>=0:devel/p5-Test-WWW-Mechanize-Catalyst

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -e '/build_requires/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
