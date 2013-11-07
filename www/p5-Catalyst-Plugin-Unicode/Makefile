# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Unicode
PORTVERSION=	0.93
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Unicode aware Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -e '/build_requires/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
