# New ports collection makefile for:	sidplug
# Date created:				14 December 2001
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	sidplug
PORTVERSION=	1.1.4
CATEGORIES=	www audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmcoopr@webmail.bmi.net

RUN_DEPENDS=	xsidplay:${PORTSDIR}/audio/xsidplay \
		mozilla:${PORTSDIR}/www/mozilla

USE_X_PREFIX=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/mozilla/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/npsidplug.so ${PREFIX}/lib/mozilla/plugins
	@${LN} -sf ${X11BASE}/bin/xsidplay ${PREFIX}/bin/sidplug
.ifndef(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Lazy_Fast.sid ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.html ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sidplug.png ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
