# New ports collection makefile for:	p5-Sledge-Plugin-XSLT
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Sledge-Plugin-XSLT
PORTVERSION=	0.01
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2457
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that adds XSLT::Dispatch::Config on

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	${SITE_PERL}/Sledge.pm:${PORTSDIR}/www/p5-Sledge
PM_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
PM_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::XSLT.3

.include <bsd.port.mk>
