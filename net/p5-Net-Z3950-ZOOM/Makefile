# New ports collection makefile for:	p5-Net-Z3950-ZOOM
# Date created:				22 December 2006
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Z3950-ZOOM
PORTVERSION=	1.14
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl interface to the Z39.50 Object-Orientation Model (ZOOM)

LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz

PERL_CONFIGURE=	yes

MAN3=		Net::Z3950::ZOOM.3 ZOOM.3

CONFLICTS=	p5-Net-Z3950-[0-9]*

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl version 5.6.0 or above
.endif

.include <bsd.port.post.mk>
