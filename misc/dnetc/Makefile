# New ports collection makefile for:    dnetc
# Date created:         26 Dec 1999
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	dnetc
PORTVERSION=	${VERSION}
PORTREVISION=	$(REVISION}
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/%SUBDIR%/ \
		ftp://ftp.distributed.net/pub/dcti/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:S/^/v/:R}
# This is architecture dependent
DISTNAME=	dnetc${PORTVERSION:E}-freebsd-${ARCH:S/i386/x86/}-elf

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Distributed.net distributed computing project client

# These are architecture dependent
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd-${ARCH:S/i386/x86/}-elf
DISTINFO_FILE=	${MASTERDIR}/distinfo.${ARCH}

ONLY_FOR_ARCHS=	i386 sparc64 amd64 powerpc

USE_RC_SUBR=	dnetc.sh
NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net

CLIENTUSER=	dnetc
CLIENTGROUP=	${CLIENTUSER}
CLIENTUID=	105

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		dnetc.1

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST=	BINDIR="${BINDIR}" \
		CLIENTUSER="${CLIENTUSER}" \
		CLIENTGROUP="${CLIENTGROUP}" \
		CLIENTUID="${CLIENTUID}"

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
.if ${OSVERSION} >= 800107
VERSION=	2.9107.516
REVISION=	0
DISTNAME=	dnetc${PORTVERSION:E}-freebsd8-${ARCH:S/i386/x86/}
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd8-${ARCH:S/i386/x86/}
.else
VERSION=	2.9108.517
REVISION=	1
DISTNAME=	dnetc${PORTVERSION:E}-freebsd7-${ARCH:S/i386/x86/}
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd7-${ARCH:S/i386/x86/}
.endif

.elif ${ARCH} == amd64
VERSION=	2.9110.519
REVISION=	0
.if ${OSVERSION} >= 800107
DISTNAME=	dnetc${PORTVERSION:E}-freebsd8-${ARCH}
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd8-${ARCH}
.else
DISTNAME=	dnetc${PORTVERSION:E}-freebsd7-${ARCH}
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E:S/b$//}-freebsd7-${ARCH}
.endif

.elif ${ARCH} == sparc64
.if ${OSVERSION} >= 800107
VERSION=	2.9109.518
REVISION=	0
DISTNAME=	dnetc${PORTVERSION:E}-freebsd8-${ARCH}
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd8-${ARCH}
.else
VERSION=	2.9103.509
REVISION=	1
DISTNAME=	dnetc${PORTVERSION:E}-freebsd7-${ARCH}-elf
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd7-${ARCH}-elf
.endif

.elif ${ARCH} == powerpc
.if ${OSVERSION} >= 800107
VERSION=	2.9109.518
REVISION=	0
DISTNAME=	dnetc${PORTVERSION:E}-freebsd8-${ARCH}
WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd8-${ARCH}
.else
BROKEN=		works on FreeBSD 8+ only in powerpc
VERSION=	0
REVISION=	0
.endif
.endif

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

	${INSTALL} -c -m 755 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc ${BINDIR}

	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc.ini ${BINDIR}/dnetc.ini.sample
.if !exists(${BINDIR}/dnetc.ini)
	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc.ini ${BINDIR}/dnetc.ini
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
