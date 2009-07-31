# New ports collection Makefile for: RT-Authen-ExternalAuth
# Date created:	        19 December 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Authen-ExternalAuth
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to authenticate users against an external source

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	RT36	"Install for rt-3.6.x (default rt-3.8.x)" off

PERL_CONFIGURE=	yes

MAN3=		RT::Authen::ExternalAuth.3 RT::User_Vendor.3

PLIST_SUB+=	RTHOME=${RTHOME}

.include <bsd.port.pre.mk>

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

# Don't use normal CONFIGURE_ARGS.  Disable doc_?????_indstall targets to
# suppress installing perllocal.pod.  This duplicates code from bsd.perl.mk
# rather undesirably.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${RT_PM_DIR} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.post.mk>
