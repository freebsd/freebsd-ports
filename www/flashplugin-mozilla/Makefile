# New ports collection makefile for:	flashplugin-mozilla
# Date created:				25 October 2001
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME?=	flashplugin-mozilla
PORTVERSION=	0.4.13
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/gplflash/gplflash/${PORTVERSION}
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	A GPL standalone Flash (TM) plugin for Mozilla web browser

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash

WRKSRC=		${WRKDIR}/${DISTNAME}/plugin

USE_XORG=	xt x11 xext
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-plugin-dir="${WEBPLUGINS_DIR}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib -lXt"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=libnpflash.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	@${REINPLACE_CMD} -e "s,-L../lib/.libs,-L${LOCALBASE}/lib,"	\
		-e "s/libnpflash.so.0.0.0/libnpflash.so.0/"	\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/npapi.h
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${CONFIGURE_WRKSRC}/configure ${CONFIGURE_WRKSRC}/ltconfig

.include <bsd.port.post.mk>
