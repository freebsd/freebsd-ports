# New ports collection makefile for:    dnetc
# Date created:         26 Dec 1999
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	dnetc
PORTVERSION=	${VERSION}
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/%SUBDIR%/ \
		http://http.distributed.net/pub/dcti/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:S/^/v/:R}
# This is architecture dependent
DISTNAME=	dnetc${PORTVERSION:E}-freebsd-${ARCH:S/i386/x86/}-elf

MAINTAINER=	tim@bishnet.net
COMMENT=	Distributed.net distributed computing project client

# These are architecture dependent
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd-${ARCH:S/i386/x86/}-elf
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}

ONLY_FOR_ARCHS=	i386 alpha sparc64 amd64

USE_RC_SUBR=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net

CLIENTUSER=	dnetc
CLIENTGROUP=	${CLIENTUSER}
CLIENTUID=	105

BINMODE=	700

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		dnetc.1

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64 || ${ARCH} == alpha
VERSION=	2.9003.481
.else
VERSION=	2.9008.491
.endif

.if ${OSVERSION} < 300000
IGNORE=		"This port requires FreeBSD 3.X or greater."
.endif

post-extract:
	@${SED} -e 's#%%CLIENTUSER%%#${CLIENTUSER}#g' -e 's#%%CLIENTGROUP%%#${CLIENTGROUP}#' \
		-e 's#%%CLIENTUID%%#${CLIENTUID}#g' ${MASTERDIR}/pkg-install > ${PKGINSTALL}
	@${SED} -e 's#%%CLIENTUSER%%#${CLIENTUSER}#g' -e 's#%%CLIENTGROUP%%#${CLIENTGROUP}#' \
		${MASTERDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} -e 's#%%BINDIR%%#${BINDIR}#' ${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${SED} -e 's#%%BINDIR%%#${BINDIR}#' \
		-e 's#%%CLIENTUSER%%#${CLIENTUSER}#g' \
		-e 's#%%RC_SUBR%%#${RC_SUBR}#g' \
		${FILESDIR}/dnetc.sh > ${WRKDIR}/dnetc.sh

do-configure:
	@if [ ! -f ${PREFIX}/dnetc.ini ]; then \
		${INSTALL} -c -m 644 ${FILESDIR}/dnetc.ini ${WRKSRC}; \
	fi

pre-install:
	@${ECHO} "==>  Creating custom user to run dnetc..."
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi
	${CHOWN} ${CLIENTUSER}:${CLIENTGROUP} ${BINDIR}
	${CHMOD} 775 ${BINDIR}

	${INSTALL} -c -m ${BINMODE} -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc ${BINDIR}

	${INSTALL_DATA} ${FILESDIR}/INFO ${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

	${INSTALL_SCRIPT} ${WRKDIR}/dnetc.sh ${PREFIX}/etc/rc.d/dnetc.sh

	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc.ini ${BINDIR}/dnetc.ini.sample
.if !exists(${BINDIR}/dnetc.ini)
	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc.ini ${BINDIR}/dnetc.ini
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
