# New ports collection Makefile for: RTx-Calendar
# Date created:	        16 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RTx-Calendar
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Calendar extension module for the RT ticketing system

LICENSE_COMB=   dual
LICENSE=        ART10 GPLv1

BUILD_DEPENDS=	p5-Date-ICal>0:${PORTSDIR}/devel/p5-Date-ICal      \
		p5-Data-ICal>0:${PORTSDIR}/deskutils/p5-Data-ICal  \
		p5-DateTime-Set>0:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	RT38
RT38_DESC=	Install for rt-3.8.x (default rt-4.0.x)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRT38}
RT_VER=		38
.else
RT_VER=		40
.endif

BUILD_DEPENDS+=	${LOCALBASE}/bin/rt:${PORTSDIR}/www/rt${RT_VER}
RUN_DEPENDS+=	${LOCALBASE}/bin/rt:${PORTSDIR}/www/rt${RT_VER}

MAN3PREFIX=	${PREFIX}

MAN3=		RTx::Calendar.3
PLIST_SUB+=	RTHOME=share/rt${RT_VER}

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{38,40}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
