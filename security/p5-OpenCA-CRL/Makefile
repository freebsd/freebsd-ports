# New ports collection makefile for:	OpenCA-CRL
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	OpenCA-CRL
PORTVERSION=	0.9.17
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	OpenCA
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	CRL Management module

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500600
	@${PERL} -pi -e 's!our \((.*?)(?=\);)!join("","use vars qw(",split(/,/,$$1))!e' \
		${WRKSRC}/*.pm
.endif
	@${MV} ${WRKSRC}/prova.pl  ${WRKSRC}/prova.pl.sample

.include <bsd.port.post.mk>
