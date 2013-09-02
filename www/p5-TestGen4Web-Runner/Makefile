# New ports collection makefile for:    p5-TestGen4Web-Runner
# Date created:				June 13th, 2006
# Whom:	      				Conor McDermottroe <ports@mcdermottroe.com>
# ex:ts=8
#
# $FreeBSD$
#

PORTNAME=	TestGen4Web-Runner
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	WWW/MACKERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	eg@fbsd.lt
COMMENT=	A PERL module to replay files recorded with TestGen4Web

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		TestGen4Web::Runner.3

.include <bsd.port.mk>
