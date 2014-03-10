# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	wizd
PORTVERSION=	24
PORTREVISION=	6
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/Sources/Sources%20v${PORTVERSION}
DISTFILES=	wizd_sources_v${PORTVERSION}.zip simplicity_v1-2.zip

MAINTAINER=	kikuchan@uranus.dti.ne.jp
COMMENT=	Open-source media server for Syabas-based media players

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread \
		libjpeg.so:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

DOS2UNIX_FILES=	Makefile nkfwrap/Makefile nkfwrap/nkfwrap_test.c \
		wizd_http.c wizd_menu.c
USE_RC_SUBR=	wizd
USES=		dos2unix zip:infozip
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
