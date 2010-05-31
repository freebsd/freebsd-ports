# New ports collection makefile for:	uvscan
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uvscan
PORTVERSION=	5.10e
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/evaluation/virusscan/english/cmdline/bsd/v5.10/
DISTNAME=	vbsd510e
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evaluation version of a DOS/Windows/Linux file virus scanner

BROKEN=		Does not fetch

# misc/compat3x is forbidden, but with FreeBSD 5.1 or later you can use
# libmap.conf(5) to map against current libc. This may affect the system
# security. Use at your own risk.
.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64"
BROKEN=		Incomplete pkg-plist
WITHOUT_COMPAT3=1
UVSCAN_LIB32=	32
USE_LDCONFIG32=	${PREFIX}/lib32
LDCONFIG=	/sbin/ldconfig -32
.else
UVSCAN_LIB32=
USE_LDCONFIG=	YES

.endif

.if defined(WITHOUT_COMPAT3)
.else
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x
.endif
LIB_DEPENDS+=	m.2:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS=		i386 amd64
NO_BUILD=		YES
NO_WRKSUBDIR=		YES

LICENSE=	shareware
RESTRICTED=	"restrictive 30 day evaluation license"

MAN1=		uvscan.1

PORTDOCS=	e5100upg.pdf readme.txt

PROGFILES=	contact.txt license.dat license.txt messages.dat \
		signlic.txt

PLIST_SUB+=	UVSCAN_LIB32=${UVSCAN_LIB32}

do-configure:
	${SED} <${FILESDIR}/uvscan.sh >${WRKSRC}/uvscan.sh \
		-e 's:@@PREFIX@@:${PREFIX}:g'
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
		<${FILESDIR}/update_dat >${WRKDIR}/update_dat

do-install:
	${MKDIR} ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan.sh ${PREFIX}/bin/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan_secure ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libbsdfv.so.4 ${PREFIX}/lib${UVSCAN_LIB32}/libbsdfv.so.4
.for filename in ${PROGFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${PREFIX}/libexec/uvscan
.endfor
.for filename in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${filename} ${MANPREFIX}/man/man1/${filename}
.endfor
.if !defined(NOPORTDOCS)
	@if ! [ -d ${DOCSDIR} ]; then ${MKDIR} ${DOCSDIR}; fi
.for filename in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin
	@${CAT} ${PKGMESSAGE}

post-install:
	${LN} -sf ${PREFIX}/lib${UVSCAN_LIB32}/libbsdfv.so.4 ${PREFIX}/lib${UVSCAN_LIB32}/libbsdfv.so
.if defined(WITHOUT_COMPAT3)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "This may affect the system security. Use at your own risk."
	@${ECHO_CMD} "You need to add the following two lines to your libmap${UVSCAN_LIB32}.conf(5):"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "[/usr/local/libexec/uvscan/uvscan]"
	@${ECHO_CMD} "libc.so.3         libc.so.4"
	@${ECHO_CMD} ""
.endif
.if !defined (PACKAGE_BUILDING)
	@${ECHO_CMD} "Trying to fetch the current DAT file"
	${SH} ${PREFIX}/sbin/update_dat
.endif

.include <bsd.port.post.mk>
