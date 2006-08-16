# New ports collection makefile for:    p5-ack
# Date created:				2006/08/15
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ack
PORTVERSION=	1.24
CATEGORIES=	textproc perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	App
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A grep-like text finder for large trees of text

PERL_CONFIGURE=	yes

MAN1=	ack.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
