# New ports collection makefile for:	Pod-Stripper
# Date created:	   18 November 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Pod-Stripper
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Strip all pod, and output what's left

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS="site"

MAN1=		podstrip.1
MAN3=		Pod::Stripper.3

post-patch:
	@${FIND} ${WRKSRC} -type f|${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//;'

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser
RUN_DEPENDS+=	${BUILD_DEPENDS}

.endif

.include <bsd.port.post.mk>
