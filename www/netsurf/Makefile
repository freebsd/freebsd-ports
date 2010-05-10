# New ports collection makefile for:	netsurf
# Date created:		17 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netsurf
PORTVERSION=	1.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://www.netsurf-browser.org/download/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight web browser

BUILD_DEPENDS=	lemon:${PORTSDIR}/devel/lemon \
		re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	mng.1:${PORTSDIR}/graphics/libmng \
		curl.6:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_GNOME=	libglade2 libxml2
MAKEFILE=	makefile
ALL_TARGET=	gtk
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
MAKE_ARGS=	CC="${CC}" SYSTEM_CC="${CC}" WARNFLAGS=

post-extract:
	@cd ${WRKSRC}/gtk/&&${CP} -RL res resderef
	@cd ${WRKSRC}/&&${MV} ChangeLog ReadMe Docs/

post-patch:
	@${REINPLACE_CMD} -e 's|	@|	|;s|-O |$${CFLAGS}|'\
		-e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/makefile

pre-build:
	@${LN} -sf ${LOCALBASE}/share/lemon/lempar.c ${WRKSRC}/css/
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/${PORTNAME}
	@${ECHO_CMD} 'export NETSURFRES=${DATADIR}/;exec ${PREFIX}/libexec/${PORTNAME}'\
		>> ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nsgtk ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@cd ${WRKSRC}/gtk/resderef/&&${COPYTREE_SHARE} . ${DATADIR}/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/Docs/&&${INSTALL_DATA} * ${DOCSDIR}/
.endif

.include <bsd.port.mk>
