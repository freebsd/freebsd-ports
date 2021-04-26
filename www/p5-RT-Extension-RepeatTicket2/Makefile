# Created by: Matthew Seaman <matthew@FreeBSD.org>

PORTNAME=	RT-Extension-RepeatTicket
PORTVERSION=	2.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RT Extension to repeat tickets base on a schedule

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER} \
		p5-DateTime-Event-ICal>0:devel/p5-DateTime-Event-ICal
RUN_DEPENDS=	${LOCALBASE}/bin/rt:www/rt${RT_VER} \
		p5-DateTime-Event-ICal>0:devel/p5-DateTime-Event-ICal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

RT_VER=		50
PLIST_SUB=	RTHOME=share/rt${RT_VER}

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
	${RM}	${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-RepeatTicket/lib/RT/Extension/RepeatTicket/Test.pm.in \
		${STAGEDIR}${PREFIX}/share/rt${RT_VER}/plugins/RT-Extension-RepeatTicket/bin/rt-repeat-ticket.in \
		${STAGEDIR}${PREFIX}/man/auto/RT/Extension/RepeatTicket/.packlist*
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/RepeatTicket 2>/dev/null || :

.include <bsd.port.mk>
