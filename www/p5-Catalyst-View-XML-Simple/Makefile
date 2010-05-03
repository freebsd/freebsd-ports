# New ports collection makefile for:	Catalyst::View::XML::Simple
# Date created:		05 Feb 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-XML-Simple
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Catalyst XML View Class

RUN_DEPENDS=	\
	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS=	\
	p5-File-Remove>0:${PORTSDIR}/devel/p5-File-Remove \
	p5-Module-Install>0:${PORTSDIR}/devel/p5-Module-Install \
	p5-Test-Base>0:${PORTSDIR}/devel/p5-Test-Base \
	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN3=	Catalyst::View::XML::Simple.3

.include <bsd.port.mk>
