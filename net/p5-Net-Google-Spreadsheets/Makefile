# Created by: Gunter Wambaugh <gunter@six-two.net>
# $FreeBSD$

PORTNAME=	Net-Google-Spreadsheets
PORTVERSION=	0.15.01
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	gunter@six-two.net
COMMENT=	Perl module for using Google Spreadsheets API

BUILD_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Mouse>=0.51:devel/p5-Mouse \
		p5-Net-Google-AuthSub>=0:net/p5-Net-Google-AuthSub \
		p5-Net-Google-DataAPI>=0.27:net/p5-Net-Google-DataAPI \
		p5-URI>=0:net/p5-URI \
		p5-XML-Atom>=0:textproc/p5-XML-Atom
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockModule>=0:devel/p5-Test-MockModule \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
