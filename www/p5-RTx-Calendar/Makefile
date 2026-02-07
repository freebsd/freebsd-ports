PORTNAME=	RTx-Calendar
PORTVERSION=	1.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calendar extension module for the RT ticketing system
WWW=		https://metacpan.org/release/RTx-Calendar

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER} \
		p5-Data-ICal>0:deskutils/p5-Data-ICal \
		p5-Date-ICal>0:devel/p5-Date-ICal \
		p5-DateTime-Set>0:devel/p5-DateTime-Set
RUN_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER} \
		p5-Data-ICal>0:deskutils/p5-Data-ICal \
		p5-Date-ICal>0:devel/p5-Date-ICal \
		p5-DateTime-Set>0:devel/p5-DateTime-Set

USES=		perl5
USE_PERL5=	configure

RT_VER=		50

NO_ARCH=	yes

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${REINPLACE_CMD} -e 's|LocalPath/man/man3|LocalPath/share/man/man3|g' ${WRKSRC}/inc/Module/Install/RTx.pm

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
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RTx/Calendar/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RTx/Calendar 2>/dev/null || :

.include <bsd.port.mk>
