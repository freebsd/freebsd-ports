# New ports collection makefile for:	p5-Net-Amazon-AWSSign
# Date created:		2011-01-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon-AWSSign
PORTVERSION=	0.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NA/NATON
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension to create signatures for AWS requests

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon::AWSSign.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
.endif

.include <bsd.port.post.mk>
