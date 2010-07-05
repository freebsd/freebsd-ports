# New ports collection makefile for:	p5-CSS-Tiny
# Date created:		2003-10-31
# Whom:			Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	CSS-Tiny
PORTVERSION=	1.17
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read/Write .css files with as little code as possible

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CSS::Tiny.3

.include <bsd.port.mk>
