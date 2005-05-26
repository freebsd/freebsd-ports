# New ports collection makefile for:    p5-Digest-SHA256
# Date created:				2005/03/24
# Whom:					Christopher Nehren
#
# $FreeBSD$
#
# The author of this port needs a good talking-to concerning naming
# consistencies. The definitions of DISTNAME *and* WRKSRC are unfortunately
# necessary at the current time.

PORTNAME=	Digest-SHA256
PORTVERSION=	0.01b
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-
DISTNAME=	SHA256-${PORTVERSION}

MAINTAINER=	apeiron+ports@coitusmentis.info
COMMENT=	Perl5 interface to the SHA256 algorithm

WRKSRC=		${WRKDIR}/SHA256-0.01
PERL_CONFIGURE=	yes

MAN3=	Digest::SHA256.3 Digest::sha256.3

.include <bsd.port.mk>
