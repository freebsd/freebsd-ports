# New ports collection makefile for:   asterisk-gui
# Date created:        31 Dec 2006
# Whom:                pneumann@gmail.com
#
# $FreeBSD$
#

PORTNAME=	asterisk-gui
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk-gui/releases/

MAINTAINER=	pneumann@gmail.com
COMMENT=	An asterisk ajax web manager

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk \
		wget:${PORTSDIR}/ftp/wget

PROJECTHOST=	asterisk-bsd
USE_AUTOTOOLS=	autoconf:262 automake:19
USE_GMAKE=	yes
SUB_FILES=	pkg-message

post-patch:
	@${GREP} -Rl '/var/lib' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g'
	@${GREP} -Rl '/etc' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g'
	@${GREP} -Rl '/bin/grep' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's|/bin/grep|grep|g'
	@${GREP} -Rl 'bash' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's|bash|sh|g'

	@${FIND} ${WRKSRC} -name "*.orig" -o -name "*.bak" | ${XARGS} ${RM}

run-autotools:
	@(cd ${WRKSRC} && ./bootstrap.sh)

checkconfig:
	@cd ${WRKSRC} && ${GMAKE} checkconfig

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
