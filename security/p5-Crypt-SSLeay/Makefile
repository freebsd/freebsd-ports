# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-SSLeay
PORTVERSION=	0.64
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to allow p5-libwww LWP to make https connections

LICENSE=	ART20

BUILD_DEPENDS=	p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny

CONFIGURE_ENV=	CRYPT_SSLEAY_LIVE_TEST_WANTED=0
MAKE_ARGS=	PASTHRU_INC=-I${OPENSSLINC}
USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-lssl32 -lssleay32 -leay32|-L${OPENSSLLIB}|' \
		-e '/is_live_test_wanted()/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
