# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	GRNOC-Config
PORTVERSION=	1.0.9
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	SF/routerproxy/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Module to allow everyone to access config files

BUILD_DEPENDS=	p5-XML-LibXML>=2:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-XPath>=1:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

PLIST_FILES=	%%SITE_PERL%%/GRNOC/Config.pm \
		%%PERL5_MAN3%%/GRNOC::Config.3.gz \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/GRNOC/Config/.packlist
PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/GRNOC/Config \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/GRNOC \
		%%SITE_PERL%%/GRNOC

.include <bsd.port.mk>
