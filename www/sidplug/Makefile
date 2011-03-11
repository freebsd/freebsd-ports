# New ports collection makefile for:	sidplug
# Date created:				14 December 2001
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	sidplug
PORTVERSION=	1.1.5
PORTREVISION=	6
CATEGORIES=	www audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Commodore 64 psid audio plugin for Mozilla or Opera

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	xsidplay:${PORTSDIR}/audio/xsidplay

MAKE_ARGS=	CC="${CC}" OPTIMIZER="${CFLAGS} -I${LOCALBASE}/include"
USE_XORG=	x11

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=npsidplug.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-install:
	@${MKDIR} ${WEBPLUGINS_DIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/npsidplug.so ${WEBPLUGINS_DIR}
	@${LN} -sf ${LOCALBASE}/bin/xsidplay ${PREFIX}/bin/sidplug
.ifndef(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Lazy_Fast.sid ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.html ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sidplug.png ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
