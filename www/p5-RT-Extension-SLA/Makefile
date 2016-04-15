# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	RT-Extension-SLA
PORTVERSION=	1.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT extension to automate due dates using service levels

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Business-Hours>0:misc/p5-Business-Hours
RUN_DEPENDS:=	${BUILD_DEPENDS}

# SLA functionality comes as standard in RT 4.4.x
CONFLICTS_INSTALL=	rt44-4.4.*

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
#WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work${RT_VER}

BUILD_DEPENDS+=	${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS+=	${LOCALBASE}/bin/rt:www/rt${RT_VER}

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

SUB_LIST+=	RTHOME=share/rt${RT_VER}
SUB_LIST+=	INITIALDATA=plugins/RT-Extension-SLA/etc/initialdata \
		SCHEMAUPGRADE=plugins/RT-Extension-SLA/etc/upgrade/0.06/content
SUB_FILES+=	pkg-message

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{38,40,42}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ${CONFIGURE_CMD} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-configure:
	${REINPLACE_CMD} "/RTxPlugin/d" ${WRKSRC}/Makefile

post-install:
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/SLA/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Extension/SLA 2>/dev/null || :

.include <bsd.port.mk>
