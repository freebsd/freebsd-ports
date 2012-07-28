# New ports collection makefile for:	Mail::Spool
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Spool
PORTVERSION=	0.50
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chifeng@gmail.com
COMMENT=	"Pure Perl" implementation of mail spooling, unspooling, and sending

BUILD_DEPENDS=	p5-File-NFSLock>=0:${PORTSDIR}/devel/p5-File-NFSLock \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Spool.3 Mail::Spool::Handle.3 Mail::Spool::Node.3

.include <bsd.port.mk>
