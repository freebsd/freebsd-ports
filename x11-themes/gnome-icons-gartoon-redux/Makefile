PORTNAME=	gartoon-redux
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	https://launchpad.net/${PORTNAME}/1.x/${PORTVERSION}/+download/

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Gartoon Redux Gnome Icon Theme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome perl5
USE_PERL5=	build

USE_GNOME=	librsvg2:build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAKE_JOBS_UNSAFE=	yes

ICONDIR=	${STAGEDIR}${PREFIX}/share/icons/GartoonRedux

do-install:
	${MKDIR} ${ICONDIR}/scalable
	${CP} -R ${WRKSRC}/build/ ${ICONDIR}
	${CP} -R ${WRKSRC}/src/ ${ICONDIR}/scalable
	${FIND} ${ICONDIR} -name '0*' -delete
	cd ${WRKSRC} && ./install-links.pl --alias-file=src/0ALIAS --icondir=${ICONDIR} 16 22 24 32

.include <bsd.port.mk>
