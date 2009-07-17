# New ports collection makefile for:	p5-SNMP
# Date created:				May 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP
PORTVERSION=	4.2.7.1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	net-snmp
PKGNAMEPREFIX=	p5-
DISTNAME=	ucd-snmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 module for interfacing with the CMU SNMP library

DEPRECATED=	Perl SNMP module is now a part of net-mgmt/net-snmp
EXPIRATION_DATE=	2009-08-15

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4

WRKSRC=		${WRKDIR}/${DISTNAME}/perl/SNMP

PERL_CONFIGURE=	yes

post-install:
		@${INSTALL_DATA} ${WRKSRC}/README \
			${PREFIX}/lib/perl5/site_perl/README.SNMP

.include <bsd.port.mk>
