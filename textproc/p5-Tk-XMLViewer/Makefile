# New ports collection makefile for:	p5-Tk-XMLViewer
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Tk-XMLViewer
PORTVERSION=	0.21
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Tk::XMLViewer - Tk widget to display XML

BUILD_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tk::XMLViewer.3
MAN1=		tkxmlview.1

.include <bsd.port.mk>
