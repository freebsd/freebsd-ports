# Ports collection Makefile for:		p5-AxKit-XSP-IfParam
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-IfParam
PORTVERSION=	1.4
CATEGORIES=	www perl5
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Equivalent of XSP Param taglib, but conditional plugin for AxKit

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		AxKit::XSP::IfParam.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
