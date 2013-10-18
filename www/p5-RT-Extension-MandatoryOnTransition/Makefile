# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RT-Extension-MandatoryOnTransition
DISTVERSION=	0.04
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Extension to require core and ticket custom fields on status changes

LICENSE=	GPLv2

BUILD_DEPENDS=	rt${RT_VER}>4.0.8:${PORTSDIR}/www/rt${RT_VER}
RUN_DEPENDS=	rt${RT_VER}>4.0.8:${PORTSDIR}/www/rt${RT_VER}

USES=	perl5
USE_PERL5=	configure

PLIST_SUB+=	RT_VER=${RT_VER}
RT_VER=	40

#MAN3PREFIX=     ${PREFIX}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt{38,40}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		unset PREFIX && \
		${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ./${CONFIGURE_SCRIPT} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
