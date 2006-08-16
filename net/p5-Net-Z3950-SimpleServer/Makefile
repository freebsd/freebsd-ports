# New ports collection makefile for:	p5-Net-Z3950-SimpleServer
# Date created:				12 March 2002
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Z3950-SimpleServer
PORTVERSION=	1.03
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A Perl module for developing Z39.50 servers

LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MAN3=	Net::Z3950::GRS1.3 Net::Z3950::SimpleServer.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	requires at least Perl 5. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
