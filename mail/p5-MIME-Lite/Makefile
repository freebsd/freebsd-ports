# New ports collection makefile for:	p5-MIME-Lite
# Date created:				August 3, 1999
# Whom:	      				Alex Perel <veers@disturbed.net>
#
# $FreeBSD$
#

PORTNAME=	MIME-Lite
PORTVERSION=	3.02.5
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9]+)$/\1/}

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	A simple interface for creating (not parsing!) MIME messages

RUN_DEPENDS=	p5-Email-Date-Format>=1.000:${PORTSDIR}/mail/p5-Email-Date-Format \
		p5-MIME-Types>=1.13:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Mail-Tools>=1.62:${PORTSDIR}/mail/p5-Mail-Tools
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		MIME::Lite.3 MIME::changes.3

post-extract:
	@${PERL} -i -ne 'print unless m,^#-, .. m,;$$, or m,^if, .. m,^},' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
