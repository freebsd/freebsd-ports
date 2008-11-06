# New ports collection makefile for:   ksh93
# Date created:                2008-10-29
# Whom:                        Joe Kelsey <joe@zircon.seattle.wa.us>
#
# $FreeBSD$
#
# This port is intended to allow interested users to easily install the
# beta versions of ksh93 releases.
#
# WARNING:
#
# No official FreeBSD support is provided to anything related to the
# ksh93 beta testing process.  Anyone who uses this port is personally
# responsible for signing up and monitoring the ast-users and
# ast-developers mailing lists and for personally reporting any ksh93
# problems on thos mailing lists.  If you try to report a ksh93-devel
# problem on the FreeBSD bug list, I will ignore it completely.
#
# I will attempt to keep the date of the beta port more or less current,
# but I will not make sure that the date is correct at all times.
# Keeping the date current in a rapidly changing beta schedule will
# depend on how quickly the various port updaters respond to correction
# notices and whether or not the ports tree is even open.  The best
# thing to do is to personally monitor the ast-users and ast-developers
# mailing lists and keep the date correct on your own copy of the port.
#
# Cannot have both ksh93 and ksh93-devel on the same machine.
#
# Visit http://www.research.att.com/sw/ for information about the
# mailing lists.
#

PORTNAME=	ksh93-devel
PORTVERSION=	${VERSION:S/-//g}
CATEGORIES=	shells
MASTER_SITES=	http://www.research.att.com/sw/download/beta/
DISTNAME=	${PORTNAME}-${VERSION}
DISTFILES=	INIT.${VERSION}.tgz ast-ksh.${VERSION}.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	joe@zircon.seattle.wa.us
COMMENT=	Official AT&T Beta release of KornShell 93

EXPIRATION_DATE=	2008-12-06
DEPRECATED=	This port is Outdated.  Please use shells/ksh93

CONFLICTS=	ksh93-200*
MANUAL_PACKAGE_BUILD=Doesn't build in tinderbox environment

VERSION=	2008-10-31
RESTRICTED=	Source recipient must acknowledge license

FETCH_ENV=	HTTP_AUTH='basic:*:I accept www.opensource.org/licenses/cpl:.'
FETCH_CMD=	/usr/bin/fetch -Rr		# see bin/76134
NO_WRKSUBDIR=	yes
MAKE_ENV=	CCFLAGS="${CFLAGS}"
.if defined(WANT_STATIC)
MAKE_ENV+=	LDFLAGS=-static
.endif

MAN1=		ksh93.1

.include <bsd.port.pre.mk>

INSTALLROOT=	${WRKSRC}/arch/freebsd${OSREL:R}.${ARCH}

do-build:
	@cd ${WRKSRC} && ${SETENV} -i ${MAKE_ENV} ${SH} bin/package make

do-install:
	${INSTALL_PROGRAM} ${INSTALLROOT}/bin/ksh ${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${INSTALLROOT}/man/man1/sh.1 \
	    ${MANPREFIX}/man/man1/ksh93.1
	${MKDIR} ${PREFIX}/share/examples/ksh93-devel
.for fun in dirs popd pushd
	${INSTALL_SCRIPT} ${INSTALLROOT}/fun/${fun} \
	    ${PREFIX}/share/examples/ksh93-devel/
.endfor

post-install:
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/ksh93 /etc/shells.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/ksh93) >/etc/shells
	@${RM} -f /etc/shells.bak

test: build
	@cd ${WRKSRC}/src/cmd/ksh93/tests && \
	    ${SETENV} SHELL=${INSTALLROOT}/bin/ksh \
		${INSTALLROOT}/bin/ksh shtests

.include <bsd.port.post.mk>
