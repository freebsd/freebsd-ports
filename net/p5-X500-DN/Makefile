# New ports collection makefile for:	X500-DN
# Date created:	   22 October 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	X500-DN
PORTVERSION=	0.28
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	X500
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Handle X.500 DNs (Distinguished Names), parse and format them

BUILD_DEPENDS=	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		X500::DN.3 X500::RDN.3

post-patch:
	@${PERL} -pi -e 's/5\.6\.1/vars qw(\$$VERSION)/; s/^our //;' \
		${WRKSRC}/DN.pm

.include <bsd.port.mk>
