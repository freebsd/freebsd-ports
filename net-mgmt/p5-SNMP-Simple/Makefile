# New ports collection makefile for:	p5-SNMP-Simple
# Date created:		2007-11-16
# Whom:			BluePex Security Solutions <freebsd-ports@bluepex.com>
#
# $FreeBSD$
#

PORTNAME=	SNMP-Simple
PORTVERSION=	0.02
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@bluepex.com
COMMENT=	Shortcuts for when using p5-SNMP

PERL_CONFIGURE=	yes

MAN3=		SNMP::Simple.3

PLIST_FILES=	%%SITE_PERL%%/SNMP/Simple.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/SNMP/Simple/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/SNMP/Simple \
		%%SITE_PERL%%/SNMP

.include <bsd.port.mk>
