# New ports collection makefile for:	p5-SNMP_Session
# Date created:				13 June 1999
# Whom:					Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	SNMP_Session
PORTVERSION=	0.83
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.switch.ch/software/sources/network/snmp/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	yes

pre-install:
	${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/Makefile;

.include <bsd.port.mk>
