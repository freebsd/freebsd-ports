# New ports collection makefile for:	p5-SNMP_Session
# Version required:			0.70
# Date created:				13 June 1999
# Whom:					Stephen J. Roznowski <sjr@home.net>
#
# $Id: Makefile,v 1.1.1.1 1999/06/27 17:41:44 cpiazza Exp $
#

DISTNAME=	SNMP_Session-0.70
PKGNAME=	p5-SNMP_Session-0.70
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.switch.ch/software/sources/network/snmp/perl/

MAINTAINER=	ports@FreeBSD.ORG

USE_PERL5=	yes

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
