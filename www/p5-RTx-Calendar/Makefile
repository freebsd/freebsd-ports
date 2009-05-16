# New ports collection Makefile for: RTx-Calendar
# Date created:	        16 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RTx-Calendar
PORTVERSION=	0.07
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

OPTIONS=	RT36 "Install for rt-3.6.x (default rt-3.8.x)" off

PERL_CONFIGURE=	yes

MAN3=		RTx::Calendar.3

PLIST_SUB+=	RTHOME=${RTHOME}

.include <bsd.port.pre.mk>

.if defined(WITH_RT36)

RTHOME?=	rt3
RT_PM_DIR=	${LOCALBASE}/${RTHOME}/lib
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt36
PLIST=		${PKGDIR}/pkg-plist.rt36
MAN3PREFIX=	${PREFIX}/${RTHOME}/local

.else

RTHOME?=	share/rt38
RT_PM_DIR=	${SITE_PERL}
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt38
PLIST=		${PKGDIR}/pkg-plist.rt38
MAN3PREFIX=	${PREFIX}

.endif

# Don't use normal CONFIGURE_ARGS.  Disable doc_?????_indstall targets to
# suppress installing perllocal.pod.  This duplicates code from bsd.perl.mk
# rather undesirably.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${RT_PM_DIR} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.post.mk>
