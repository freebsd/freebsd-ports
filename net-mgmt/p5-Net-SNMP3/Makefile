# New ports collection makefile for:	p5-Net-SNMP
# Date created:				30 June 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SNMP
PORTVERSION=	3.50
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-3.5
USE_PERL5=	yes
MAN3=		Net::SNMP.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
