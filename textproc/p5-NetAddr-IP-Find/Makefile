# New ports collection makefile for:	p5-NetAddr-IP-Find
# Date created:				May 14th 2002
# Whom:					Alex Kapranoff <kappa@freebsd.org.ua>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP-Find
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/NetAddr/IP.pm:${PORTSDIR}/net/p5-NetAddr-IP

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		NetAddr::IP::Find.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
