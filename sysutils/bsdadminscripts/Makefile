# New ports collection makefile for:	bsdadminscripts
# Date created:		15 May 2006
# Whom:			Dominic Fandrey <lon_kamikaze@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bsdadminscripts
PORTVERSION=	2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lon_kamikaze@gmx.de
COMMENT=	A small collection of administration scripts

NO_BUILD=	yes
MANCOMPRESSED=	no

MAN1=		bsdadminscripts.1

RC_SCRIPTS=	start stop restart status onestart onestop onerestart onestatus
PORT_SCRIPTS=	config build clean fetch package
BUILDFLAGS_FILES=	buildflags.mk buildflags.awk buildflags.conf

.if !defined(WITHOUT_RCSTART)
PLIST_FILES+=	${RC_SCRIPTS:S,^,sbin/rc,}
MAN1+=		rcstart.1
.endif

.if !defined(WITHOUT_PORTCONFIG)
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/sysutils/portupgrade
PLIST_FILES+=	${PORT_SCRIPTS:S,^,sbin/port,}
MAN1+=		portconfig.1
.endif

.if !defined(WITHOUT_BUILDFLAGS)
PLIST_FILES+=	${BUILDFLAGS_FILES:S,^,share/$(PORTNAME)/,}
PLIST_DIRS+=	share/${PORTNAME}
MAN1+=		buildflags.mk.1 buildflags.conf.1 buildflags.awk.1
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
.if !defined(WITHOUT_BUILDFLAGS)
	@${ECHO_MSG} "===>  Installing buildflags."
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
.for _file in ${BUILDFLAGS_FILES}
	@${INSTALL} ${WRKSRC}/${_file} ${PREFIX}/share/${PORTNAME}/
.endfor
.endif
	@${ECHO_MSG} "===>  Installing man pages."
.for _manpage in ${MAN1}
	@${INSTALL} ${WRKSRC}/${_manpage} ${PREFIX}/man/man1/
.endfor

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
