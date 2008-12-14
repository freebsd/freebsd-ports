# New ports collection Makefile for: RTx-Calendar
# Date created:	        16 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RTx-Calendar
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Calendar extension module for the RT ticketing system

BUILD_DEPENDS=	${LOCALBASE}/${RTHOME}/bin/rt:${PORTSDIR}/www/rt36     	      \
		${SITE_PERL}/Date/ICal.pm:${PORTSDIR}/devel/p5-Date-ICal      \
		${SITE_PERL}/Data/ICal.pm:${PORTSDIR}/deskutils/p5-Data-ICal  \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS=	${BUILD_DEPENDS}

RTHOME?=	rt3
PLIST_SUB+=	RTHOME=${RTHOME}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	RTHOME=${PREFIX}/${RTHOME}

MAN3PREFIX=	${PREFIX}/${RTHOME}/local
MAN3=		RTx::Calendar.3

# Don't use normal CONFIGURE_ARGS
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} \
	    ${PERL5} ./${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
