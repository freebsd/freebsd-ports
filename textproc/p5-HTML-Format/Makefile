# New ports collection makefile for:	p5-HTML-Format
# Date created:				25 April 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-Format
PORTVERSION=	2.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A module to format HTML to text or PS

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Font-AFM>=0:${PORTSDIR}/x11-fonts/p5-Font-AFM \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
INSTALL_TARGET=	pure_install
MAN3=		HTML::Formatter.3 HTML::FormatPS.3 HTML::FormatRTF.3 HTML::FormatText.3

.include <bsd.port.mk>
