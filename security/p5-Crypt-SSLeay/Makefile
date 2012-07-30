# New ports collection makefile for:	p5-Crypt-SSLeay
# Date created:				December-15-2000
# Whom:	      				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-SSLeay
PORTVERSION=	0.60
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to allow p5-libwww LWP to make https connections

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny

CONFIGURE_ARGS=	--lib=${OPENSSLBASE} --no-live-tests
MAKE_ARGS=	PASTHRU_INC=-I${OPENSSLINC}
PERL_CONFIGURE=	yes
USE_OPENSSL=	yes

MAN3=		Crypt::SSLeay.3 Net::SSL.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
