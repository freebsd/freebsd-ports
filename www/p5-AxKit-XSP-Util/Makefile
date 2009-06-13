# Ports collection Makefile for:		p5-AxKit-XSP-Util
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-Util
PORTVERSION=	1.6
CATEGORIES=	www perl5
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	XSP util: taglib plugin for AxKit

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit \
		${SITE_PERL}/${PERL_ARCH}/HTTP/GHTTP.pm:${PORTSDIR}/www/p5-HTTP-GHTTP \
		${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		AxKit::XSP::Util.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
