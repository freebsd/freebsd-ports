# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RT-Extension-MandatoryOnTransition
DISTVERSION=	0.20
PORTREVISION=  2
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Extension to require core and ticket custom fields on status changes

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}

FLAVOR?=       ${FLAVORS:[1]}
FLAVORS=       rt44 rt50
rt44_PKGNAMEPREFIX=    p5-RT44-
rt44_CONFLICTS_INSTALL= rt50
rt50_PKGNAMEPREFIX=    p5-RT50-
rt50_CONFLICTS_INSTALL= rt44

.if ${FLAVOR} == rt44
RT_VER=		       44
.elif ${FLAVOR} == rt50
RT_VER=		       50
.endif

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PLIST_SUB+=	RT_VER=${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{44,50}.  Hence ignore
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
