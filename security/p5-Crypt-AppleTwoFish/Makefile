# New ports collection Makefile for:	p5-Crypt-AppleTwoFish
# Date created:				18 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-AppleTwoFish
PORTVERSION=	0.051
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for Apple iTMS internal key descrambling algorithm

PERL_CONFIGURE=	yes

MAN3=		Crypt::AppleTwoFish.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
post-patch:
	${PERL} -pi -e '$$_="" if m{5.008|warnings}' ${WRKSRC}/t/*.t \
		${WRKSRC}/lib/Crypt/AppleTwoFish.pm ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.post.mk>
