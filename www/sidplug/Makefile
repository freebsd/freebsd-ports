# New ports collection makefile for:	sidplug
# Date created:				14 December 2001
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	sidplug
PORTVERSION=	1.1.5
CATEGORIES=	www audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Commodore 64 psid audio plugin for Mozilla or Opera

RUN_DEPENDS=	xsidplay:${PORTSDIR}/audio/xsidplay

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/npsidplug.so ${PREFIX}/lib/browser_plugins
	@${LN} -sf ${X11BASE}/bin/xsidplay ${PREFIX}/bin/sidplug
.ifndef(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Lazy_Fast.sid ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.html ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sidplug.png ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
