# New ports collection Makefile for: RT-Authen-ExternalAuth
# Date created:	        19 December 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Authen-ExternalAuth
DISTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FALCONE
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to authenticate users against an external source

LICENSE=	GPLv2

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	RT38	"Install for rt-3.8.x (default rt-4.0.x)" off

.include <bsd.port.options.mk>

.if defined(WITH_RT38)
RT_VER=		38
.else
RT_VER=		40
.endif

BUILD_DEPENDS+=	${SITE_PERL}/RT.pm:${PORTSDIR}/www/rt${RT_VER}
RUN_DEPENDS+=	${SITE_PERL}/RT.pm:${PORTSDIR}/www/rt${RT_VER}

MAN3PREFIX=	${PREFIX}

MAN3=		RT::Authen::ExternalAuth.3
PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{38,40}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
