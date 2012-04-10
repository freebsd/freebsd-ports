# New ports collection makefile for:	p5-XML-Canonical
# Date created:		2007-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Canonical
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl Implementation of Canonical XML

BUILD_DEPENDS=	p5-XML-GDOME>=0:${PORTSDIR}/textproc/p5-XML-GDOME
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	gdome:${PORTSDIR}/textproc/gdome2

PERL_CONFIGURE=	yes

MAN3=		XML::Canonical.3

.include <bsd.port.mk>
