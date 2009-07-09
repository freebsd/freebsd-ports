# New ports collection makefile for:	Catalyst-View-XSLT
# Date created:	   10 Apr 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-XSLT
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JA/JANUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	XSLT view class for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-XML-LibXSLT>=1.52:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		p5-Path-Class>=0.12:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Catalyst::Helper::View::XSLT.3 Catalyst::View::XSLT.3 \
		Catalyst::View::XSLT::XML::LibXSLT.3

.include <bsd.port.mk>
