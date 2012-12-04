# New ports collection Makefile for:    exmh2
# Date created:			1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $FreeBSD$
#

# "+=" and "?=" lines are for sharing this Makefile with japanese/exmh2.

PORTNAME=	exmh
PORTVERSION=	2.7.2
PORTREVISION=	5
CATEGORIES+=	mail tk
MASTER_SITES=	${MASTER_SITE_TCLTK} \
		SF

MAINTAINER?=	cy@FreeBSD.org
COMMENT?=	X11/TK based mail reader front end to MH

.if defined(JAPANESE_EXMH)
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80
BUILD_DEPENDS=	tclsh8.0jp:${PORTSDIR}/japanese/tcl80
WISH=		wish8.0jp
TCLSH=		tclsh8.0jp
.else
RUN_DEPENDS=	wish8.6:${PORTSDIR}/x11-toolkits/tk86
BUILD_DEPENDS=	tclsh8.6:${PORTSDIR}/lang/tcl86
WISH=		wish8.6
TCLSH=		tclsh8.6
.endif

# exmh is pretty useless without this, but it's not needed to build it.
.if defined(JAPANESE_EXMH)
RUN_DEPENDS+=	repl:${PORTSDIR}/japanese/mh
.else
RUN_DEPENDS+=	repl:${PORTSDIR}/mail/nmh
SCRIPTS_ENV+=	USE_NMH=YES
.endif

# full mime support needs mmencode/mmdecode from metamail
RUN_DEPENDS+=	mmencode:${PORTSDIR}/mail/metamail

# Additionally, exmh will use the following ports if present:
# lang/expect
# textproc/glimpse
# security/gnupg
# security/pgp
# security/pgp5
# mail/faces
# audio/rplay

PLIST_SUB=	EXMH_VERSION=${PORTVERSION}

MAN1=		exmh.1

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include <bsd.port.mk>
