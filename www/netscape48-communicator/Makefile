# New ports collection makefile for:	netscape (full communicator version)
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME?=	netscape-${BROWSER_ARC}
PORTVERSION?=	${BROWSER_VER}
CATEGORIES?=	www
MASTER_SITES?=	ftp://ftp.netscape.com/pub/communicator/4.08/english/unix/unsupported/freebsd/professional_edition/
DISTFILES?=	communicator-v408-export.x86-unknown-freebsd.tar.gz

MAINTAINER?=	sada@FreeBSD.org

RUN_DEPENDS+=	netscape:${PORTSDIR}/www/netscape-wrapper

.if (${PORTVERSION} == "4.76")
BROKEN=		"has a serious security hole, use 4.77 instead"
.endif

.if !defined(INFILE_HEAD)
# not included from master ports
NO_LATEST_LINK=	yes
.endif

USE_XLIB=	yes
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
STRIP=
WRKSRC?=	${WRKDIR}/${BROWSER}-v408.x86-unknown-freebsd
PKGDIR=		${.CURDIR}

AUTOADMIN?=	autoadmin-v408.x86-unknown-freebsd.tar.gz
BROWSER?=	communicator
BROWSER_ARC?=	${BROWSER}
BROWSER_VER?=	4.08
FORTIFY=	Fortify-1.4.6-unix-x86
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape
BINDIR=		${PREFIX}/bin
INFILE_HEAD?=	'Communicator,4.08.0.98306'
WRAPPER_TEMPLATE=	${MASTERDIR}/files/netscape.sh
MAILCAP?=	${MASTERDIR}/files/mailcap

PLIST_SUB=	BROWSER=${BROWSER_ARC} BROWSER_VER=${BROWSER_VER} \
		NSUBDIR=${NSUBDIR}

.if (${BROWSER} == "communicator") && !defined(NO_AUTOADMIN)
DISTFILES+=	${AUTOADMIN}
.endif

.if defined(WITH_128BIT) && !defined(NO_FORTIFY)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	${FORTIFY}.tar.gz
RESTRICTED=	"Contains strong cryptography"
.endif

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

.if ${ARCH} == "alpha"
RUN_DEPENDS+=	/compat/osf1/usr/shlib/libc.so:${PORTSDIR}/emulators/osf1_base
.endif

.if (${ARCH} == "i386") && !defined(USE_LINUX_LIB) && !defined(WITHOUT_AOUT)
USE_AOUT_LIB=	yes
PKGREQ=		${MASTERDIR}/pkg-req.aout
RUN_DEPENDS+=	${X11BASE}/lib/aout/libX11.so.6.1:${PORTSDIR}/x11/XFree86-aoutlibs
.endif

.SILENT:

.if !defined(WITH_128BIT) && !defined(NO_FORTIFY)
pre-extract:
	${ECHO} "You can make Netscape use 128-bit encryption by defining WITH_128BIT"
.endif

post-configure:
	${SED}	-e "s;@PREFIX@;${PREFIX};g" -e "s;@NSUBDIR@;${NSUBDIR};g" \
		-e "s;@BROWSER@;${BROWSER_ARC};g" \
		-e "s;@BROWSER_VER@;${BROWSER_VER};g" \
		${WRAPPER_TEMPLATE} >${WRKSRC}/netscape
	${CHMOD} +x ${WRKSRC}/netscape
	${ECHO} -n ${INFILE_HEAD},${NDIR} >${WRKSRC}/infile

.if defined(USE_AOUT_LIB)
pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL
.endif

do-install:
	${MKDIR} ${NDIR}/java/classes
	${INSTALL_DATA} ${WRKSRC}/*.jar ${NDIR}/java/classes
	${INSTALL_PROGRAM} ${WRKSRC}/vreg ${NDIR}
	for i in ${WRKSRC}/*.nif; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $${i} ${EXTRACT_AFTER_ARGS} -C ${NDIR}; \
	done
	${WRKSRC}/vreg ${NDIR}/registry ${WRKSRC}/infile
	${MV} -f ${NDIR}/netscape ${NDIR}/${BROWSER_ARC}-${BROWSER_VER}.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape \
		${BINDIR}/${BROWSER_ARC}-${BROWSER_VER}
	${LN} -sf ${BROWSER_ARC}-${BROWSER_VER} ${BINDIR}/${BROWSER_ARC}-4
	${LN} -sf ${BROWSER_ARC}-4 ${BINDIR}/netscape.run
	if [ ! -f ${NDIR}/mailcap ] ; then \
		${INSTALL_DATA} ${MAILCAP} ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
.if (${BROWSER} == "communicator") && !defined(NO_AUTOADMIN)
	tar zxf ${DISTDIR}/${AUTOADMIN} -C ${NDIR}
.endif
.if defined(WITH_128BIT) && !defined(NO_FORTIFY)
	cd ${WRKDIR}/${FORTIFY} \
	&& (${ECHO}; ${ECHO} yes; ${ECHO} no; ${ECHO} no) \
	| ./Fortify.sh ${NDIR}/${BROWSER_ARC}-${BROWSER_VER}.bin
.endif
	${CHOWN} -R root:wheel ${NDIR}

post-install:
	${CAT} ${DESCR}

# hack to allow slave ports to include bsd.port.pre.mk and then this file
.if defined(_PREMKINCLUDED)
.include <bsd.port.post.mk>
.else
.include <bsd.port.mk>
.endif
