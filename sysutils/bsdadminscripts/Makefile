# New ports collection makefile for:	bsdadminscripts
# Date created:		15 May 2006
# Whom:			Dominic Fandrey <lon_kamikaze@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bsdadminscripts
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lon_kamikaze@gmx.de
COMMENT=	A small collection of administration scripts

NO_BUILD=	yes

RC_SCRIPTS=	start stop restart status onestart onestop onerestart onestatus
PORT_SCRIPTS=	config build clean fetch package

.if !defined(WITHOUT_RCSTART)
PLIST_FILES+=	${RC_SCRIPTS:S,^,sbin/rc,}
.endif

.if !defined(WITHOUT_PORTCONFIG)
RUN_DEPENDS=	portupgrade:${PORTSDIR}/sysutils/portupgrade
PLIST_FILES+=	${PORT_SCRIPTS:S,^,sbin/port,}
.endif

do-install:
.if !defined(WITHOUT_RCSTART)
	@${ECHO_MSG} "===>  Installing rcstart."
	@${INSTALL} ${WRKSRC}/rcstart ${PREFIX}/sbin/
.for _link in ${RC_SCRIPTS:Nstart}
	@${LN} ${PREFIX}/sbin/rcstart ${PREFIX}/sbin/rc${_link}
.endfor
.endif
.if !defined(WITHOUT_PORTCONFIG)
	@${ECHO_MSG} "===>  Installing portconfig."
	@${INSTALL} ${WRKSRC}/portconfig ${PREFIX}/sbin/
.for _link in ${PORT_SCRIPTS:Nconfig}
	@${LN} ${PREFIX}/sbin/portconfig ${PREFIX}/sbin/port${_link}
.endfor
.endif

.include <bsd.port.mk>
