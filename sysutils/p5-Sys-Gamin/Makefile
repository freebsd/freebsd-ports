# New ports collection makefile for:	p5-Sys-Gamin
# Date created:		03 May 2007
# Whom: 	Nick Hibma <n_hibma@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Sys-Gamin
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	n_hibma@FreeBSD.org
COMMENT=	Perl interface to Gamin (File Access Monitor implementation)

PERL_CONFIGURE=	yes
USE_FAM=	yes
MAN1=	monitor.1
MAN3=	Sys::Gamin.3

pre-configure:
	${PERL} -pi -e 'm/LIBS =>/ && print " INC => \"-I${LOCALBASE}/include\",\n"' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
