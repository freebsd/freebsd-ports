# New ports collection makefile for:	Email::MIME::Creator::ISO_2022_JP
# Date created:		19 Nov 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Creator-ISO_2022_JP
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of Email::MIME mixin to create an iso-2022-jp mail

RUN_DEPENDS=	\
	p5-Email-MIME>=1.900:${PORTSDIR}/mail/p5-Email-MIME \
	p5-Sub-Install>0:${PORTSDIR}/devel/p5-Sub-Install
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MIME::Creator::ISO_2022_JP.3

.include <bsd.port.mk>
