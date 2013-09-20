# Created by: loader <loader@freebsdmall.com>
# $FreeBSD$

PORTNAME=	HTML-FormatText-WithLinks
PORTVERSION=	0.14
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	loader@freebsdmall.com
COMMENT=	Perl5 module to convert HTML to text with links as footnotes

BUILD_DEPENDS=	p5-HTML-Format>=0:${PORTSDIR}/textproc/p5-HTML-Format \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAN3=		HTML::FormatText::WithLinks.3

NO_STAGE=	yes
.include <bsd.port.mk>
