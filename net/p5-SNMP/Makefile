# New ports collection makefile for:	p5-SNMP
# Version required:			1.8b3
# Date created:				May 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	SNMP-1.8.1
PKGNAME=	p5-SNMP-1.8.1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP

MAINTAINER=	jfitz@FreeBSD.org

LIB_DEPENDS= 	snmp.4:${PORTSDIR}/net/ucd-snmp

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
		@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/lib/perl5/site_perl/README.SNMP

.include <bsd.port.mk>
