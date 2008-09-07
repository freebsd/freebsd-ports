# New ports collection makefile for:	p5-Plucene-Simple
# Date created:		2 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plucene-Simple
DISTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STRYTOAST
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interface to Plucene

BUILD_DEPENDS=	p5-Time-Piece>=1.08:${PORTSDIR}/devel/p5-Time-Piece \
		p5-Time-Piece-Range>=1.0:${PORTSDIR}/devel/p5-Time-Piece-Range \
		p5-Plucene>=1.09:${PORTSDIR}/textproc/p5-Plucene \
		p5-File-Find-Rule>=0.10:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Slurp>=2002.1031:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-Class>=0.03:${PORTSDIR}/devel/p5-Test-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES

MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
