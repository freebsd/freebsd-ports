# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	wizd
PORTVERSION=	24
PORTREVISION=	5
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/Sources/Sources%20v${PORTVERSION}
DISTFILES=	wizd_sources_v${PORTVERSION}.zip simplicity_v1-2.zip

MAINTAINER=	kikuchan@uranus.dti.ne.jp
COMMENT=	Open-source media server for Syabas-based media players

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread \
		libjpeg.so:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

USE_DOS2UNIX=	Makefile nkfwrap/Makefile nkfwrap/nkfwrap_test.c \
		wizd_http.c wizd_menu.c
USE_RC_SUBR=	wizd
USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|./skin|${DATADIR}/skins|' ${WRKSRC}/wizd.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wizd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/wizd.conf ${STAGEDIR}${PREFIX}/etc/wizd.conf.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/skins
	cd ${WRKSRC} && ${COPYTREE_SHARE} "simplicity simplicity_hires" \
		${STAGEDIR}${DATADIR}/skins

.include <bsd.port.mk>
