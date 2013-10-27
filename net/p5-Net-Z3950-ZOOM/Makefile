# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Z3950-ZOOM
PORTVERSION=	1.28
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl interface to the Z39.50 Object-Orientation Model (ZOOM)

LIB_DEPENDS=	yaz:${PORTSDIR}/net/yaz
BUILD_DEPENDS=	p5-MARC-Record>=1.38:${PORTSDIR}/textproc/p5-MARC-Record
RUN_DEPENDS=	p5-MARC-Record>=1.38:${PORTSDIR}/textproc/p5-MARC-Record

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Z3950::ZOOM.3 ZOOM.3

CONFLICTS=	p5-Net-Z3950-[0-9]*

NO_STAGE=	yes
.include <bsd.port.mk>
