PORTNAME=	roboto-fonts-ttf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.138
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	wulf@cicgroup.ru
COMMENT=	Roboto family of fonts
WWW=		https://github.com/googlefonts/roboto-2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	googlefonts
GH_PROJECT=	roboto-2

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_SUB=	FCDIR=${FCDIR} \
		FCDIR_LINKS=${FCDIR_LINKS}

FCDIR?=		etc/fonts/conf.avail
FCDIR_LINKS=	${FCDIR:S|conf.avail|conf.d|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/hinted/*.ttf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${FCDIR}/ ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/
	${INSTALL_DATA} ${FILESDIR}/*.conf ${STAGEDIR}${PREFIX}/${FCDIR}/
	cd ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ && ${LN} -fs ../conf.avail/*.conf .

.include <bsd.port.mk>
