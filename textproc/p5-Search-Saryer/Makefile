# New ports collection makefile for:	Search::Saryer
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Search-Saryer
PORTVERSION=	0.10
CATEGORIES=	textproc perl5
MASTER_SITES=	ftp://ftp.namazu.org/sary/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	sary.8:${PORTSDIR}/textproc/sary

PERL_CONFIGURE=	yes

MAN3=		Search::Saryer.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
