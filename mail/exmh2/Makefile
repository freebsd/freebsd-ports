# New ports collection Makefile for:    exmh2
# Date created:			1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $FreeBSD$
#

# "+=" and "?=" lines are for sharing this Makefile with japanese/exmh2.
PORTNAME=	exmh
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES+=	mail tk83
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/
MASTER_SITES+=	ftp://tcl.activestate.com/pub/tcl/%SUBDIR%/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	bmah@FreeBSD.org

.if defined(JAPANESE_EXMH)
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80
BUILD_DEPENDS=	tclsh8.0jp:${PORTSDIR}/japanese/tcl80
WISH=		wish8.0jp
TCLSH=		tclsh8.0jp
.else
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83
WISH=		wish8.3
TCLSH=		tclsh8.3
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
# misc/glimpse
# security/gnupg
# security/pgp
# security/pgp5
# security/pgp6
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
