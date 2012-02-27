# New ports collection makefile for:	p5-Net-SSLeay
# Date created:				April 17th 2000
# Whom:	      				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SSLeay
PORTVERSION=	1.45
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to SSL

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_PREFIX=${OPENSSLBASE}
USE_OPENSSL=	yes

MAN3=		Net::SSLeay.3 Net::SSLeay::Handle.3

PORTEXAMPLES=	*

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/req.conf ${EXAMPLESDIR}/req.conf
.endif

.include <bsd.port.mk>
