# New ports collection makefile for:	p5-Mail-CClient
# Date created:				01 July 2000
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=		CClient
PORTVERSION=		1.0
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=		p5-
DISTNAME=		Mail-Cclient-${PORTVERSION}

MAINTAINER=		kbyanc@posi.net

LIB_DEPENDS=		c-client4.8:${PORTSDIR}/mail/cclient

PERL_CONFIGURE=		yes

MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=			Mail::Cclient.3

.include <bsd.port.mk>
