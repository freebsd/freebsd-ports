# Created by: kftseng@iyard.org
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-X509
PORTVERSION=	1.8.2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}00.${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL X509 API

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/^cc_optimize_flags/ s| -Werror||' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
