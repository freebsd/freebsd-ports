# New ports collection makefile for:	p5-SNMP
# Date created:				May 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP
PORTVERSION=	4.2.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS= 	snmp.4:${PORTSDIR}/net/net-snmp

PERL_CONFIGURE=	yes

post-install:
		@${INSTALL_DATA} ${WRKSRC}/README \
			${PREFIX}/lib/perl5/site_perl/README.SNMP

.include <bsd.port.mk>
