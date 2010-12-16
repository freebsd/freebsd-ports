# New ports collection Makefile for: RT-Extension-SLA
# Date created:	        23 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-SLA
PORTVERSION=	0.03
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to automate due dates using service levels

BUILD_DEPENDS=	${SITE_PERL}/Business/Hours.pm:${PORTSDIR}/misc/p5-Business-Hours
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	RT36 "Install for rt-3.6.x (default rt-3.8.x)" off

.include <bsd.port.options.mk>

.if defined(WITH_RT36)

RTHOME?=	rt3
SUB_LIST+=	INITIALDATA=local/etc/Extension-SLA/initialdata
RT_PM_DIR=	${LOCALBASE}/${RTHOME}/lib
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt36
PLIST=		${PKGDIR}/pkg-plist.rt36
MAN3PREFIX=	${PREFIX}/${RTHOME}/local

.else

RTHOME?=	share/rt38
SUB_LIST+=	INITIALDATA=plugins/RT-Extension-SLA/etc/initialdata
RT_PM_DIR=	${SITE_PERL}
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt38
PLIST=		${PKGDIR}/pkg-plist.rt38
MAN3PREFIX=	${PREFIX}

.endif

MAN3=		RT::Action::SLA.3                     \
		RT::Action::SLA_SetDefault.3          \
		RT::Action::SLA_SetDue.3              \
		RT::Action::SLA_SetStarts.3           \
		RT::Condition::SLA.3                  \
		RT::Condition::SLA_RequireDefault.3   \
		RT::Condition::SLA_RequireDueSet.3    \
		RT::Condition::SLA_RequireStartsSet.3 \
		RT::Extension::SLA.3                  \
		RT::Queue_SLA.3

PLIST_SUB+=	RTHOME=${RTHOME}

SUB_LIST+=	RTHOME=${RTHOME}
SUB_FILES+=	pkg-message

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt3{6,8}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${RT_PM_DIR} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
