# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PGP
PORTVERSION=	0.3a
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl5 module to work with PGP messages

RUN_DEPENDS=	pgpin:security/pgpin

PORTSCOUT=	skipv:1.0

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|WriteMakefile;|WriteMakefile( 'NAME' => "PGP::Pipe" );|' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^=over 4/d' ${WRKSRC}/PGP/Pipe.pm

pre-configure:
	@${CP} ${WRKSRC}/PGP/Pipe.pm ${WRKSRC}

.include <bsd.port.mk>
