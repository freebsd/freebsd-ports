# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Template-Plugin-Autoformat
PORTVERSION=	2.71
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Template Toolkit interface to Text::Autoformat module

RUN_DEPENDS=	p5-Template-Toolkit>=2.22:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-Autoformat>0:${PORTSDIR}/textproc/p5-Text-Autoformat
BUILD_DEPENDS=	p5-Template-Toolkit>=2.22:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-Autoformat>0:${PORTSDIR}/textproc/p5-Text-Autoformat

USES=		perl5
USE_PERL5=	configure

MAN3=	Template::Plugin::Autoformat.3

NO_STAGE=	yes
.include <bsd.port.mk>
