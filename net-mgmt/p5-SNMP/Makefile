# New ports collection makefile for:	p5-SNMP
# Version required:			1.6
# Date created:				May 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1997/06/27 01:53:13 jfitz Exp $
#

DISTNAME=	SNMP-1.6
PKGNAME=	p5-SNMP-1.6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/libsnmp.a:${PORTSDIR}/net/ucd-snmp

BROKEN=		build

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
		@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/lib/perl5/site_perl/README.SNMP

.include <bsd.port.mk>
