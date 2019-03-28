# Created by: Matthew Seaman <m.seaman@infracaninophile.co.uk>
# $FreeBSD$

PORTNAME=	RTx-Calendar
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Calendar extension module for the RT ticketing system

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1+


BUILD_DEPENDS=	p5-Date-ICal>0:devel/p5-Date-ICal      \
		p5-Data-ICal>0:deskutils/p5-Data-ICal  \
		p5-DateTime-Set>0:devel/p5-DateTime-Set \
		${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS=	p5-Date-ICal>0:devel/p5-Date-ICal      \
		p5-Data-ICal>0:deskutils/p5-Data-ICal  \
		p5-DateTime-Set>0:devel/p5-DateTime-Set \
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

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

MAN3PREFIX=	${PREFIX}

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

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
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RTx/Calendar/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RTx/Calendar 2>/dev/null || :

.include <bsd.port.mk>
