# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	RT-Authen-ExternalAuth
DISTVERSION=	0.12
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT extension to authenticate users against an external source

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-perl-ldap>0:${PORTSDIR}/net/p5-perl-ldap \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

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
