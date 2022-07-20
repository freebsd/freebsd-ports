PORTNAME=	RT-Extension-CommandByMail
PORTVERSION=	3.00
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sysadmin@gkg.net
COMMENT=	RT Extension to change ticket metadata via email

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER}

USES=		perl5
USE_PERL5=	configure

RT_VER=		44

NO_ARCH=	yes

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt44.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		unset PREFIX && \
		${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ${CONFIGURE_CMD} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-configure:
	${REINPLACE_CMD} "/RTxPlugin/d" ${WRKSRC}/Makefile

post-install:
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/CommandByMail/.packlist
	${RM} ${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-CommandByMail/lib/RT/Extension/CommandByMail/Test.pm.in
	${RM} ${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-CommandByMail/lib/RT/Extension/CommandByMail/Test.pm
	${RM} ${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-CommandByMail/etc/handle_action_pass_currentuser.patch
	${RMDIR} -p ${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-CommandByMail/etc 2>/dev/null || :
	${RMDIR} -p ${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-CommandByMail/lib/RT/Extension/CommandByMail >/dev/null || :
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/CommandByMail 2>/dev/null || :

.include <bsd.port.mk>
