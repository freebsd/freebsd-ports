# New ports collection makefile for:	p5-Net-Z3950-ZOOM
# Date created:				22 December 2006
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Z3950-ZOOM
PORTVERSION=	1.25
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl interface to the Z39.50 Object-Orientation Model (ZOOM)

LIB_DEPENDS=	yaz.3:${PORTSDIR}/net/yaz
BUILD_DEPENDS=	p5-MARC-Record>=1.38:${PORTSDIR}/textproc/p5-MARC-Record
RUN_DEPENDS=	p5-MARC-Record>=1.38:${PORTSDIR}/textproc/p5-MARC-Record

PERL_CONFIGURE=	yes

MAN3=		Net::Z3950::ZOOM.3 ZOOM.3

CONFLICTS=	p5-Net-Z3950-[0-9]*

.include <bsd.port.mk>
