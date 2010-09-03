# New ports collection makefile for:    p5-Crypt-OpenSSL-X509
# Date created:				2007/06/09
# Whom:					kftseng@iyard.org
#
# $FreeBSD$
#

PORTNAME=	Crypt-OpenSSL-X509
PORTVERSION=	1.4
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL X509 API

PERL_CONFIGURE=	yes

MAN3=		Crypt::OpenSSL::X509.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.include <bsd.port.post.mk>
