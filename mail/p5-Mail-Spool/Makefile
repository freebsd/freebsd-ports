# New ports collection makefile for:	Mail::Spool
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Spool
PORTVERSION=	0.50
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A "pure perl" implementation of mail spooling, unspooling and sending

BUILD_DEPENDS=	${SITE_PERL}/File/NFSLock.pm:${PORTSDIR}/devel/p5-File-NFSLock \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Mail::Spool.3 Mail::Spool::Handle.3 Mail::Spool::Node.3

.include <bsd.port.mk>
