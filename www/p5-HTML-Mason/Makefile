# $FreeBSD$

PORTNAME=	HTML-Mason
PORTVERSION=	1.52
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	High-performance, dynamic web site authoring system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cache-Cache>=1:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Class-Container>=0.07:${PORTSDIR}/devel/p5-Class-Container \
		p5-Exception-Class>=1.15:${PORTSDIR}/devel/p5-Exception-Class \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Log-Any>=0.08:${PORTSDIR}/devel/p5-Log-Any \
		p5-Params-Validate>=0.70:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CHI>=0.210:${PORTSDIR}/devel/p5-CHI \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

OPTIONS_DEFINE=	MODPERL

USES=		perl5
USE_PERL5=	configure

MODPERL_BUILD_DEPENDS=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2
MODPERL_RUN_DEPENDS=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2
MODPERL_USE=		APACHE_RUN=22+

post-patch:
	@${REINPLACE_CMD} -e '/bin\/convert/d' ${WRKSRC}/Makefile.PL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script/mason.pl ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
