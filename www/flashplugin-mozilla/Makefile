# New ports collection makefile for:	flashplugin-mozilla
# Date created:				25 October 2001
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME?=	flashplugin-mozilla
PORTVERSION=	0.4.13
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	A GPL standalone Flash (TM) plugin for Mozilla web browser

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash

WRKSRC=		${WRKDIR}/${DISTNAME}/plugin

USE_BZIP2=	yes
USE_X_PREFIX=	yes
PLUGIN_DIR=	lib/browser_plugins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-plugin-dir="${PREFIX}/${PLUGIN_DIR}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXt"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s,-L../lib/.libs,-L${LOCALBASE}/lib,"	\
		-e "s/libnpflash.so.0.0.0/libnpflash.so.0/"	\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/npapi.h

.include <bsd.port.mk>
