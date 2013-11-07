# Created by: ijliao
# $FreeBSD$

PORTNAME=	WebService-Technorati
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl interface to the Technorati web services interface

BUILD_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
