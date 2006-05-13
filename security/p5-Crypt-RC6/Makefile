# New ports collection makefile for:    p5-Crypt-RC6
# Date created:				2002/09/20
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Crypt-RC6
PORTVERSION=	1.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the RC6 encryption algorithm

PERL_CONFIGURE=	yes

MAN3=		Crypt::RC6.3

do-patch:
	${REINPLACE_CMD} -e 's///' ${WRKSRC}/RC6.pm

.include <bsd.port.mk>
