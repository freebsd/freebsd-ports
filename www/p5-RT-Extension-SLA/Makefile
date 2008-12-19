# New ports collection Makefile for: RT-Extension-SLA
# Date created:	        23 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-SLA
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to automate due dates using service levels

BUILD_DEPENDS=	${LOCALBASE}/${RTHOME}/bin/rt:${PORTSDIR}/www/rt36     	      \
		${SITE_PERL}/Business/Hours.pm:${PORTSDIR}/misc/p5-Business-Hours
RUN_DEPENDS=	${BUILD_DEPENDS}

RTHOME?=	rt3
PLIST_SUB+=	RTHOME=${RTHOME}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	RTHOME=${PREFIX}/${RTHOME}

MAN3PREFIX?=	${PREFIX}/${RTHOME}/local
MAN3=		RT::Action::SLA_SetDefault.3				 \
		RT::Condition::SLA_RequireDueSet.3 RT::Condition::SLA.3	 \
		RT::Condition::SLA_RequireDefault.3 RT::Extension::SLA.3 \
		RT::Condition::SLA_RequireStartsSet.3 RT::Queue_SLA.3	 \
		RT::Action::SLA_SetStarts.3 RT::Action::SLA.3

# Don't use normal CONFIGURE_ARGS.  Disable doc_?????_indstall targets to
# suppress installing perllocal.pod.  This duplicates code from bsd.perl.mk
# rather undesirably.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile


.include <bsd.port.mk>
