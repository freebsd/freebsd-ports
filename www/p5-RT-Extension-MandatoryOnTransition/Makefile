# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RT-Extension-MandatoryOnTransition
DISTVERSION=	0.18
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Extension to require core and ticket custom fields on status changes

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}

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

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PLIST_SUB+=	RT_VER=${RT_VER}

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
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/MandatoryOnTransition/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/MandatoryOnTransition 2>/dev/null || :

.include <bsd.port.mk>
