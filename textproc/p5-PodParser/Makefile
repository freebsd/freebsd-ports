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

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
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

.include <bsd.port.mk>
