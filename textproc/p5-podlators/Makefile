# New ports collection makefile for:	podlators
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	podlators
PORTVERSION=	1.21
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2man.1 pod2text.1
MAN3=		Pod::Man.3 Pod::ParseLink.3 Pod::Text.3 Pod::Text::Color.3 \
		Pod::Text::Overstrike.3 Pod::Text::Termcap.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
