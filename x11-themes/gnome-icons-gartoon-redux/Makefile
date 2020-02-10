# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	gartoon-redux
PORTVERSION=	1.11
CATEGORIES=	x11-themes gnome
MASTER_SITES=	https://launchpad.net/${PORTNAME}/1.x/${PORTVERSION}/+download/

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Gartoon Redux Gnome Icon Theme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsvg-convert:graphics/librsvg2

USES=		perl5
USE_PERL5=	build

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
INSTALLS_ICONS=	yes

MAKE_JOBS_UNSAFE=	yes

ICONDIR=	${STAGEDIR}${PREFIX}/share/icons/GartoonRedux

do-install:
	${MKDIR} ${ICONDIR}/scalable
	${CP} -R ${WRKSRC}/build/ ${ICONDIR}
	${CP} -R ${WRKSRC}/src/ ${ICONDIR}/scalable
	${FIND} ${ICONDIR} -name '0*' -delete
	cd ${WRKSRC} && ./install-links.pl --alias-file=src/0ALIAS --icondir=${ICONDIR} 16 22 24 32

.include <bsd.port.mk>
