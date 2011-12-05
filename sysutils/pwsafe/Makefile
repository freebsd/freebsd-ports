# New ports collection makefile for:	pwsafe
# Date created:				29 Mars 2004
# Whom:					donnex
#
# $FreeBSD$
#

PORTNAME=	pwsafe
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=	donnex@donnex.net
COMMENT=	Cmdline program that manages encrypted password databases

OPTIONS=	SETUID	"Install setuid pwsafe binary" off \
		X11	"Build with X11 libraries" off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		pwsafe.1
PLIST_FILES=	bin/pwsafe

.include <bsd.port.options.mk>

.if defined(WITH_X11)
CONFIGURE_ARGS=	--with-x
USE_XORG=	ice sm x11 xmu
.else
CONFIGURE_ARGS=	ac_cv_have_x="have_x=no" \
		ac_cv_lib_ICE_IceConnectionNumber=no \
		ac_cv_lib_X11_XOpenDisplay=no \
		ac_cv_lib_Xmu_XmuInternAtom=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwsafe ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pwsafe.1 ${PREFIX}/man/man1/
.if defined(WITH_SETUID)
	${CHMOD} u+s ${PREFIX}/bin/pwsafe
.endif

.include <bsd.port.mk>
