# New ports collection makefile for:   ksh93
# Date created:                2000-12-26
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	ksh93
PORTVERSION=	${VERSION:S/-//g}
CATEGORIES=	shells
FETCH_ENV=	HTTP_AUTH='basic:*:I accept www.opensource.org/licenses/cpl:.'
MASTER_SITES=	http://www.research.att.com/~gsf/download/tgz/
DISTNAME=	${PORTNAME}-${VERSION}
DISTFILES=	INIT.${VERSION}.tgz ast-ksh.${VERSION}.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	joe@zircon.seattle.wa.us
COMMENT=	Official AT&T release of KornShell 93

VERSION=	2005-02-02
RESTRICTED=    "Source recipient must acknowledge license"

FETCH_CMD=	/usr/bin/fetch -Rr		# see bin/76134
NO_WRKSUBDIR=	yes
MAKE_ENV=	CCFLAGS="${CFLAGS}" SHELL="${SH}"
.if defined(WANT_STATIC)
MAKE_ENV+=	LDFLAGS=-static
.endif

MAN1=		ksh93.1
INSTALLROOT=	${WRKSRC}/arch/freebsd.${ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

do-build:
	@cd ${WRKSRC} && env -i ${MAKE_ENV} ${SH} bin/package make

do-install:
	${INSTALL_PROGRAM} ${INSTALLROOT}/bin/ksh ${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${INSTALLROOT}/man/man1/sh.1 \
	    ${MANPREFIX}/man/man1/ksh93.1
	${MKDIR} ${PREFIX}/share/examples/ksh93
.for fun in dirs popd pushd
	${INSTALL_SCRIPT} ${INSTALLROOT}/fun/${fun} \
	    ${PREFIX}/share/examples/ksh93/
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
