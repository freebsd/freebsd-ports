PORTNAME=	roboto-fonts-ttf
DISTVERSIONPREFIX=	v
DISTVERSION=	3.015
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/roboto-3-classic/releases/download/${DISTVERSIONFULL}/
EXTRACT_SUFX=	.zip
DISTFILES=	Roboto_${DISTVERSIONFULL}.zip

MAINTAINER=	wulf@cicgroup.ru
COMMENT=	TrueType Roboto family fonts
WWW=		https://github.com/googlefonts/roboto-3-classic

LICENSE=	OFL11

USES=		fonts
FONTNAME=	Roboto

EXTRACT_AFTER_ARGS=	--strip-components 2 \
			--include hinted/static/*.ttf \
			--no-same-owner --no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_SUB=	FCDIR=${FCDIR} \
		FCDIR_LINKS=${FCDIR_LINKS}

FCDIR?=		etc/fonts/conf.avail
FCDIR_LINKS=	${FCDIR:S|conf.avail|conf.d|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${FCDIR}/ ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/
	${INSTALL_DATA} ${FILESDIR}/*.conf ${STAGEDIR}${PREFIX}/${FCDIR}/
	cd ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ && ${LN} -fs ../conf.avail/*.conf .

.include <bsd.port.mk>
