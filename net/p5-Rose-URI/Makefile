# New ports collection makefile for:	p5-Rose-URI
# Date created:	   			18 Nov, 2010
# Whom:		   			Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Rose-URI
PORTVERSION=	1.00
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Easy and efficient manipulation of URI components

RUN_DEPENDS=	p5-Rose-Object>=0.854:${PORTSDIR}/devel/p5-Rose-Object \
		p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Rose::URI.3

.include <bsd.port.mk>
