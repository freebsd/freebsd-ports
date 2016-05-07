# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	RT-Extension-LDAPImport
PORTVERSION=	0.36
PORTREVISION=	2
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT extension to import users from an LDAP store

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

BUILD_DEPENDS=	p5-perl-ldap>0:net/p5-perl-ldap \
		p5-Class-Accessor>0:devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes

USES+=		perl5
USE_PERL5=	configure

OPTIONS_SINGLE=			RTVERSION
OPTIONS_SINGLE_RTVERSION=	RT40 RT42 RT44
RT40_DESC=			Install for rt-4.0.x (www/rt40)
RT42_DESC=			Install for rt-4.2.x (www/rt42)
RT44_DESC=			Install for rt-4.4.x (www/rt44)
OPTIONS_DEFAULT=		RT44

.include <bsd.port.options.mk>

.for opt in ${OPTIONS_SINGLE_RTVERSION}
.if ${PORT_OPTIONS:M${opt}}
RT_VER=         ${opt:S/RT//}
.endif
.endfor

### Temporary for debugging
#WRKDIR=         ${WRKDIRPREFIX}${.CURDIR}/work${RT_VER}

BUILD_DEPENDS+=	${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS+=	${LOCALBASE}/bin/rt:www/rt${RT_VER}

MAN3PREFIX=	${PREFIX}

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{40,42,44}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ${CONFIGURE_CMD} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-configure:
	${REINPLACE_CMD} "/RTxPlugin/d" ${WRKSRC}/Makefile

post-install:
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/LDAPImport/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/LDAPImport 2>/dev/null || :

.include <bsd.port.mk>
