# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	HTTP-MobileAgent
PORTVERSION=	0.36
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KURIHARA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP mobile user agent string parser for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-HTTP-Message>=1.43:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Scalar-List-Utils>=1.14:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		ja-p5-WWW-MobileCarrierJP>=0.04:${PORTSDIR}/japanese/p5-WWW-MobileCarrierJP \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
