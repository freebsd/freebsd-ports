# New ports collection makefile for:	podlators
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	podlators
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site

MAN1=		pod2man.1 pod2text.1
MAN3=		Pod::Man.3 Pod::ParseLink.3 Pod::Text.3 Pod::Text::Color.3 \
		Pod::Text::Overstrike.3 Pod::Text::Termcap.3

CONFLICTS=	perl-5.6.* perl-5.8.*

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
.endif

.include <bsd.port.post.mk>
