# Created by: Geyer Klaus
# $FreeBSD$

PORTNAME=	catseye-fm
PORTVERSION=	4.2.0.0
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://catseye-fm.sourceforge.net/downloads/ \
		http://catseye-fm-temp.sourceforge.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clear, fast, powerful file browser using gtk+2.0

LICENSE=	GPLv3

USES=		pkgconfig
USE_GNOME=	gtk20

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catseye-fm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/user_install.sh ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/catseye_XML_config_file.conf.sample \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/icons && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
