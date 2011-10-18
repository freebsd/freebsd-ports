# New ports collection Makefile for: RT-Extension-LDAPImport
# Date created:	        24 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-LDAPImport
PORTVERSION=	0.31
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to import users from an LDAP store

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	RT38 "Install for rt-3.8.x (default rt-4.0.x)" off

.include <bsd.port.options.mk>

.if defined(WITH_RT38)
RT_VER=		38
.else
RT_VER=		40
.endif

BUILD_DEPENDS+=	${SITE_PERL}/RT.pm:${PORTSDIR}/www/rt${RT_VER}
RUN_DEPENDS+=	${SITE_PERL}/RT.pm:${PORTSDIR}/www/rt${RT_VER}

MAN3PREFIX=	${PREFIX}

MAN3=		RT::Extension::LDAPImport.3
PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt3{6,8}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
