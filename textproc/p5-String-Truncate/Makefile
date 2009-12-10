# New ports collection makefile for:	textproc/p5-String-Truncate
# Date created:				6 December 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Truncate
PORTVERSION=	0.102
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A module for when strings are too long to be displayed in...

RUN_DEPENDS=	p5-Sub-Exporter>=0.953:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Install>=0.03:${PORTSDIR}/devel/p5-Sub-Install
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		String::Truncate.3

.include <bsd.port.mk>
