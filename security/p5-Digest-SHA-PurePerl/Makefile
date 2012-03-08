# Ports collection Makefile for:	p5-Digest-SHA-PurePerl
# Date created:				21 Dec, 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-SHA-PurePerl
PORTVERSION=	5.70
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl extension for SHA-1/224/256/384/512 in pure Perl

PERL_CONFIGURE=	yes

MAN3=		Digest::SHA::PurePerl.3

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/dups ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
