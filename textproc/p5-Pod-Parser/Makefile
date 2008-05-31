# New ports collection makefile for:	Pod::Parser
# Date created:		18 Dec 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-Parser
PORTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Modules to work with POD (Plain Old Documentation)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Pod::Checker.3 Pod::Find.3 Pod::InputObjects.3 \
		Pod::ParseUtils.3 Pod::Parser.3 Pod::PlainText.3 Pod::Select.3 \
		Pod::Usage.3

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} {} \;

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
BUILD_DEPENDS+=	p5-Test-Simple>=0.60:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
