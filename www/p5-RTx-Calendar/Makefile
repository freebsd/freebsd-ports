# New ports collection Makefile for: RTx-Calendar
# Date created:	        16 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RTx-Calendar
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Calendar extension module for the RT ticketing system

BUILD_DEPENDS=	${SITE_PERL}/Date/ICal.pm:${PORTSDIR}/devel/p5-Date-ICal      \
		${SITE_PERL}/Data/ICal.pm:${PORTSDIR}/deskutils/p5-Data-ICal  \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

RTHOME?=	share/rt38
RT_PM_DIR=	${SITE_PERL}
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt38
MAN3PREFIX=	${PREFIX}

MAN3=		RTx::Calendar.3
PLIST_SUB+=	RTHOME=${RTHOME}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt3{6,8}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${RT_PM_DIR} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
