# New ports collection makefile for:	p5-MIME-Lite
# Date created:				August 3, 1999
# Whom:	      				Alex Perel <veers@disturbed.net>
#
# $FreeBSD$
#

PORTNAME=	MIME-Lite
PORTVERSION=	3.02.0
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple interface for creating (not parsing!) MIME messages

RUN_DEPENDS=	p5-Mail-Tools>=1.62:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Types>=1.13:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Email-Date>=0:${PORTSDIR}/mail/p5-Email-Date
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		MIME::Lite.3 MIME::changes.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
.endif

post-extract:
	@${PERL} -i -ne 'print unless m,^#-, .. m,;$$, or m,^if, .. m,^},' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
