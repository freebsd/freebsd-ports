# New ports collection makefile for:    p5-Crypt-Anubis
# Date created:				31 Oct 2003
# Whom:					Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Anubis
PORTVERSION=	1.0.4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crypt::CBC-compliant block cipher

PERL_CONFIGURE=	yes

MAN3=		Crypt::Anubis.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw{$$1};$$1/g' ${WRKSRC}/Anubis.pm
.endif

.include <bsd.port.post.mk>
