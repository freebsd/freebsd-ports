# New ports collection makefile for:	p5-SNMP-Util
# Date created:				September 7 1999
# Whom:					Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP-Util
PORTVERSION=	1.6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP
PKGNAMEPREFIX=	p5-

MAINTAINER=	fenner@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net/p5-SNMP

USE_PERL5=	yes

MAN3=		SNMP::Util.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
