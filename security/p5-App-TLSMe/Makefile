# New ports collection makefile for:	App::TLSMe
# Date created:		06 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-TLSMe
PORTVERSION=	0.100000
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0000$//}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for TLS/SSL tunnel

RUN_DEPENDS=	\
	p5-AnyEvent>=5.34:${PORTSDIR}/devel/p5-AnyEvent \
	p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

PERL_CONFIGURE=	yes

MAN1=	tlsme.1
MAN3=	App::TLSMe.3 \
	App::TLSMe::Connection.3 \
	App::TLSMe::Pool.3

.include <bsd.port.mk>
