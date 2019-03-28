# Created by: Michael Schout <mschout@gkg.net>
# $FreeBSD$

PORTNAME=	RT-Extension-QuickAssign
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sysadmin@gkg.net
COMMENT=	RT Extension to add owner change links on ticket display page

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

# this is not compatible with RT 4.4 at this time.
CONFLICTS_INSTALL= rt44
RT_VER=42

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt42.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		unset PREFIX && \
		${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ${CONFIGURE_CMD} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-configure:
	${REINPLACE_CMD} "/RTxPlugin/d" ${WRKSRC}/Makefile

post-install:
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/QuickAssign/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/QuickAssign 2>/dev/null || :

.include <bsd.port.mk>
