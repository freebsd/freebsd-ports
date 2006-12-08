# New ports collection Makefile for:	p5-Crypt-Lite
# Date created:				18 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Lite
PORTVERSION=	0.82.11
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for a symmetric data encryption and decryption

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::Lite.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/lib/Crypt/Lite.pm
	${PERL} -pi -e '$$_="" if m{5.6.1}' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.post.mk>
