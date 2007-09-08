# New ports collection makefile for:	p5-BBS-UserInfo-Maple3itoc
# Date created:		2006-08-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	BBS-UserInfo-Maple3itoc
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GS/GSLIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Get user information of Maple3itoc-style BBS

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect

PERL_CONFIGURE=	5.8.0+	# Inherited from lang/p5-Expect

MAN3=		BBS::UserInfo::Maple3itoc.3

.include <bsd.port.mk>
