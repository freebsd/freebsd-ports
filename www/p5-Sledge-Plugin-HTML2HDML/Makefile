# New ports collection makefile for:	p5-Sledge-Plugin-HTML2HDML
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Sledge-Plugin-HTML2HDML
PORTVERSION=	0.01
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2451
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Sledge plug-in that invokes html2hdml for EZweb WAP/1.0 clients

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS} \
		html2hdml:${PORTSDIR}/www/html2hdml

PM_DEPENDS=	${SITE_PERL}/Sledge.pm:${PORTSDIR}/www/p5-Sledge
PM_DEPENDS+=	${SITE_PERL}/HTTP/MobileAgent.pm:${PORTSDIR}/www/p5-HTTP-MobileAgent

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::HTML2HDML.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
