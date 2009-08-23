# New ports collection makefile for:	p5-File-Rsync
# Date created:				20 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	File-Rsync
PORTVERSION=	0.43
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl convenience wrapper for the rsync(1) program

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Rsync.3

.include <bsd.port.mk>
