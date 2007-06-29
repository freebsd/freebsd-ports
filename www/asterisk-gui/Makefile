# New ports collection makefile for:   asterisk-gui
# Date created:        31 Dec 2006
# Whom:                pneumann@gmail.com
#
# $FreeBSD$
#

PORTNAME=	asterisk-gui
PORTVERSION=	0.0.1r20070627
CATEGORIES=	www
MASTER_SITES=	http://asterisk-bsd.googlecode.com/files/
DISTNAME=	${PORTNAME}-snap-2007-06-27

MAINTAINER=	pneumann@gmail.com
COMMENT=	An asterisk ajax web manager

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_AUTOTOOLS=	automake:19
USE_GMAKE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

OPTIONS=	SIP_QUEUES	"In queues register users as SIP, not Agents" off \
		SAMPLE_CONFIG   "Install sample configuration files" off

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/config/backup.html \
		${WRKSRC}/config/syslog.html \
		${WRKSRC}/config/scripts/astman.js \
		${WRKSRC}/tools/zapscan.c \
		${WRKSRC}/tools/zapscan \
		${WRKSRC}/scripts/gui_sysinfo \
		${WRKSRC}/scripts/listfiles
	@${FIND} ${WRKSRC} -name "*.orig" -o -name "*.bak" | ${XARGS} ${RM}

run-autotools:
	@(cd ${WRKSRC} && ./bootstrap.sh)

checkconfig:
	@cd ${WRKSRC} && ${GMAKE} checkconfig

.include <bsd.port.pre.mk>

.if defined(WITH_SIP_QUEUES)
EXTRA_PATCHES+=	${FILESDIR}/extra-config-queues.html
.endif

post-install:
.if defined(WITH_SAMPLE_CONFIG)
		@cd ${WRKSRC} && ${GMAKE} samples
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
