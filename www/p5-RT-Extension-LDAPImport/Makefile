# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	RT-Extension-LDAPImport
PORTVERSION=	0.36
PORTREVISION=	3
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT extension to import users from an LDAP store

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-perl-ldap>0:net/p5-perl-ldap \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		${LOCALBASE}/bin/rt:www/rt${RT_VER}

FLAVOR?=	${FLAVORS:[1]}
FLAVORS=	rt44 rt42
rt42_PKGNAMEPREFIX=	p5-RT42-
rt42_CONFLICTS_INSTALL= rt44
rt44_PKGNAMEPREFIX=	p5-RT44-
rt44_CONFLICTS_INSTALL= rt42

.if ${FLAVOR} == rt44
RT_VER=		44
.elif ${FLAVOR} == rt42
RT_VER=		42
.endif

USES+=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

MAN3PREFIX=	${PREFIX}

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{42,44}.  Hence ignore
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
