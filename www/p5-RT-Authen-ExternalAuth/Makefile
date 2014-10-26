# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	RT-Authen-ExternalAuth
DISTVERSION=	0.25
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

NO_ARCH=	yes

USES+=		perl5
USE_PERL5=	configure

OPTIONS_SINGLE=                 RTVERSION
OPTIONS_SINGLE_RTVERSION=       RT40 RT42
RT40_DESC=                      Install for rt-4.0.x (www/rt40)
RT42_DESC=                      Install for rt-4.2.x (www/rt42)
OPTIONS_DEFAULT=                RT42

.include <bsd.port.options.mk>

.for opt in 40 42
.if ${PORT_OPTIONS:MRT${opt}}
RT_VER=         ${opt}
.endif
.endfor

### Temporary for debugging
#WRKDIR=         ${WRKDIRPREFIX}${.CURDIR}/work${RT_VER}

BUILD_DEPENDS+=	${LOCALBASE}/bin/rt:${PORTSDIR}/www/rt${RT_VER}
RUN_DEPENDS+=	${LOCALBASE}/bin/rt:${PORTSDIR}/www/rt${RT_VER}

MAN3PREFIX=	${PREFIX}

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{40,42}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm

do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//;' Makefile

.include <bsd.port.mk>
