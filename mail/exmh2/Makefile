# New ports collection Makefile for:    exmh2
# Version required:		2.1.1
# Date created:			1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $FreeBSD$
#

# "?=" lines are for sharing this Makefile with japanese/exmh2.
DISTNAME=	exmh-2.1.1
CATEGORIES?=	mail tk82
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/exmh/

MAINTAINER?=	markm@FreeBSD.org

.if defined(JAPANESE_EXMH)
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80
BUILD_DEPENDS=	tclsh8.0jp:${PORTSDIR}/japanese/tcl80
WISH=		wish8.0jp
TCLSH=		tclsh8.0jp
.else
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
BUILD_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82
WISH=		wish8.2
TCLSH=		tclsh8.2
.endif

# exmh is pretty useless without this, but it's not needed to build it.
.if defined(JAPANESE_EXMH)
RUN_DEPENDS+=	repl:${PORTSDIR}/japanese/mh
.else
.if defined(USE_MH)
RUN_DEPENDS+=	repl:${PORTSDIR}/mail/mh
.else
RUN_DEPENDS+=	repl:${PORTSDIR}/mail/nmh
SCRIPT_ENV+=	USE_NMH=YES
.endif
.endif

# full mime support needs mmencode/mmdecode from metamail
RUN_DEPENDS+=	mmencode:${PORTSDIR}/mail/metamail

# Additionally, exmh will use the following ports if present:
# lang/expect
# misc/glimpse
# security/gnupg
# security/pgp
# security/pgp5
# mail/faces
# audio/rplay

PLIST_SUB=	EXMH_VERSION=2.1.1

MAN1=		exmh.1

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include <bsd.port.mk>
