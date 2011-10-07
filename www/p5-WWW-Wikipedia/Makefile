# New ports collection makefile for:	p5-WWW-Wikipedia
# Date created:				Aug 5 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	WWW-Wikipedia
PORTVERSION=	2.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRICAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module of Automated interface to the Wikipedia

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Text-Autoformat>=0:${PORTSDIR}/textproc/p5-Text-Autoformat
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		wikipedia.1
MAN3=		WWW::Wikipedia.3 \
		WWW::Wikipedia::Entry.3

.include <bsd.port.mk>
