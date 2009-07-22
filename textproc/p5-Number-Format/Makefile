# New ports collection makefile for:	Number::Format
# Date created:				27 Oct 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Number-Format
PORTVERSION=		1.72a
CATEGORIES=		textproc perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		clsung@FreeBSD.org
COMMENT=		Perl extension for formatting numbers

PERL_CONFIGURE=		yes

MAN3=			Number::Format.3
WRKSRC=			${WRKDIR}/${PORTNAME}-1.72

post-patch:
	${PERL} -pi -e 's/en_US/en_US.US-ASCII/' ${WRKSRC}/t/*.t

.include <bsd.port.mk>
