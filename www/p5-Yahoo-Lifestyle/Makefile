# New ports collection makefile for:	www/p5-Yahoo-Lifestyle
# Date created:				16 Jan 2008
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Yahoo-Lifestyle
PORTVERSION=	0.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcchien@hcchien.org
COMMENT=	A simple interface for Yahoo! Taiwan Lifestyle open APIs

BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-Yahoo-BBAuth>=0:${PORTSDIR}/security/p5-Yahoo-BBAuth \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=		Yahoo::Lifestyle.3

.include <bsd.port.mk>
