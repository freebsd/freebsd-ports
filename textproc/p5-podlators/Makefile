# New ports collection makefile for:	podlators
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	podlators
PORTVERSION=	1.27
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

RUN_DEPENDS=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site

MAN1=		pod2man.1 pod2text.1
MAN3=		Pod::Man.3 Pod::ParseLink.3 Pod::Text.3 Pod::Text::Color.3 \
		Pod::Text::Overstrike.3 Pod::Text::Termcap.3

.include <bsd.port.pre.mk>

PLIST_SUB=	PL_FILES=""

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
.elif ${PERL_LEVEL} < 500802
.undef MAN1
PLIST_SUB=	PL_FILES="@comment "
.endif

post-patch:
.if ${PERL_LEVEL} >= 500600 && ${PERL_LEVEL} < 500802
	@${PERL} -pi -e 'm,pod2man|pod2text, && s,.,,sg' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
