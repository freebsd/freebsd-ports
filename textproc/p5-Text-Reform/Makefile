# New ports collection makefile for:	textproc/p5-Text-Reform
# Date created:				2 August 2002
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Text-Reform
PORTVERSION=	1.12.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Text/DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manual text wrapping and reformatting

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version

PERL_CONFIGURE=	yes

MAN3=		Text::Reform.3

.include <bsd.port.mk>
