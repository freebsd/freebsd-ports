# New ports collection makefile for:	p5-File-Rsync
# Date created:				20 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	File-Rsync
PORTVERSION=	0.20
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		File::Rsync.3

.include <bsd.port.mk>
