# New ports collection Makefile for: RT-Authen-ExternalAuth
# Date created:	        19 December 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Authen-ExternalAuth
PORTVERSION=	0.08
PORTREVISION=	3
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to authenticate users against an external source

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	RT36	"Install for rt-3.6.x (default rt-3.8.x)" off

.include <bsd.port.options.mk>

.if defined(WITH_RT36)

PORTVERSION=	0.05
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

MAN3=		RT::Authen::ExternalAuth.3 RT::User_Vendor.3
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
