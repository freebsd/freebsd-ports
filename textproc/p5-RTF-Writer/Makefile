# New ports collection makefile for:	textproc/p5-RTF-Writer
# Date created:				Oct 15th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	RTF-Writer
PORTVERSION=	1.11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RTF
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for generating documents in Rich Text Format

BUILD_DEPENDS=	${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	RTF::Writer.3 \
	RTF::Writer::TableRowDecl.3 \
	RTF::Cookbook.3

.include <bsd.port.mk>
