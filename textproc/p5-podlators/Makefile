# New ports collection makefile for:	podlators
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	podlators
PORTVERSION=	1.25
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

RUN_DEPENDS=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+= INSTALLDIRS=site

MAN1=		pod2man.1 pod2text.1
MAN3=		Pod::Man.3 Pod::ParseLink.3 Pod::Text.3 Pod::Text::Color.3 \
		Pod::Text::Overstrike.3 Pod::Text::Termcap.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
