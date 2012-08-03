# New ports collection Makefile for: RT-Extension-SLA
# Date created:	        23 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-SLA
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT extension to automate due dates using service levels

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Business-Hours>0:${PORTSDIR}/misc/p5-Business-Hours
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	RT38
RT38_DESC=	Install for rt-3.8.x (default rt-4.0.x)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRT38}
RT_VER=		38
.else
RT_VER=		40
.endif

BUILD_DEPENDS+=	${LOCALBASE}/bin/rt:${PORTSDIR}/www/rt${RT_VER}
RUN_DEPENDS+=	${LOCALBASE}/bin/rt:${PORTSDIR}/www/rt${RT_VER}

MAN3PREFIX=	${PREFIX}

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

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

SUB_LIST+=	RTHOME=share/rt${RT_VER}
SUB_LIST+=	INITIALDATA=plugins/RT-Extension-SLA/etc/initialdata \
		SCHEMAUPGRADE=plugins/RT-Extension-SLA/etc/upgrade/0.06/content
SUB_FILES+=	pkg-message

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{38,40}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
