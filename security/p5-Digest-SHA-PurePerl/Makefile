# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Digest-SHA-PurePerl
PORTVERSION=	5.81
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl extension for SHA-1/224/256/384/512 in pure Perl

USES=		perl5
USE_PERL5=	configure

PORTEXAMPLES=	dups
MAN3=	Digest::SHA::PurePerl.3

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${EXAMPLESDIR}

.endif

.include <bsd.port.mk>
