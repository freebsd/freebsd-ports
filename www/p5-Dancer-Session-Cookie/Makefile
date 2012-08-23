# New ports collection makefile for:	Dancer::Session::Cookie
# Date created:		23 Aug 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Session-Cookie
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encrypted cookie-based session backend for Dancer

RUN_DEPENDS=	\
	p5-Crypt-CBC>0:${PORTSDIR}/security/p5-Crypt-CBC \
	p5-Crypt-Rijndael>0:${PORTSDIR}/security/p5-Crypt-Rijndael \
	p5-Dancer>=1.13:${PORTSDIR}/www/p5-Dancer \
	p5-String-CRC32>0:${PORTSDIR}/devel/p5-String-CRC32
TEST_DEPENDS=	\
	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-NoWarnings>0:${PORTSDIR}/devel/p5-Test-NoWarnings
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Dancer::Session::Cookie.3

.include <bsd.port.mk>
