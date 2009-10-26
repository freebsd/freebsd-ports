# New ports collection makefile for:	p5-CSP
# Date created:			2005-04-13
# Whom:				David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	CSP
PORTVERSION=	0.34
CATEGORIES=	security perl5
MASTER_SITES=	ftp://ftp.it.su.se/pub/users/leifj/ \
		http://redundancy.redundancy.org/mirror/
PKGNAMEPREFIX=	p5-

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A Perl tool for managing Certificate Authorities

BUILD_DEPENDS=	${SITE_PERL}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Term/Prompt.pm:${PORTSDIR}/devel/p5-Term-Prompt \
		${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CSP.3

.include <bsd.port.mk>
