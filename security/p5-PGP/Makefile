# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PGP
PORTVERSION=	0.3a
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl5 module to work with PGP messages

BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgpin

PORTSCOUT=	skipv:1.0

ONLY_FOR_ARCHS=	i386 alpha amd64 sparc64

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|WriteMakefile;|WriteMakefile( 'NAME' => "PGP::Pipe" );|' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^=over 4/d' ${WRKSRC}/PGP/Pipe.pm

pre-configure:
	@${CP} ${WRKSRC}/PGP/Pipe.pm ${WRKSRC}

.include <bsd.port.mk>
