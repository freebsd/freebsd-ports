# New ports collection makefile for:	Pod::Parser
# Date created:		18 Dec 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PodParser
PORTVERSION=	1.18
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2usage.1 podchecker.1 podselect.1
MAN3=		Pod::Checker.3 Pod::Find.3 Pod::InputObjects.3 \
		Pod::ParseUtils.3 Pod::Parser.3 Pod::PlainText.3 Pod::Select.3 \
		Pod::Usage.3
MAN1PREFIX=	${PREFIX}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} {} \;

.include <bsd.port.pre.mk>

SITE_PERL?=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

perl_major=${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=${_perl_minor:C|^.*(...)|\1|}
.if ${perl_minor} >= 100
perl_minor=${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=${PERL_VERSION:C|^.*(..)|\1|}
.else # ${perl_minor} < 100
_perl_patch=0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=${_perl_patch:C|^.*(..)|\1|}
.endif # ${perl_minor} < 100
PERL_LEVEL=${perl_major}${perl_minor}${perl_patch}

BUILD_DEPENDS=
.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif # ${PERL_LEVEL} < 500601

.include <bsd.port.post.mk>
