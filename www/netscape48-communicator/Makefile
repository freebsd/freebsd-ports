# New ports collection makefile for:	netscape (full communicator version)
# Version required:     4.*
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id$
#

DISTNAME=	netscape-${BROWSER}-${BROWSER_VER}
CATEGORIES=	www
MASTER_SITES?=	ftp://ftp.netscape.com/pub/communicator/4.08/english/unix/unsupported/freebsd/professional_edition/
DISTFILES?=	communicator-v408-export.x86-unknown-freebsd.tar.gz ${AUTOADMIN}
AUTOADMIN=	autoadmin-v408.x86-unknown-freebsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

Y2K=		http://home.netscape.com/products/year2000/faq/client.html

ONLY_FOR_ARCHS=	i386

NO_FILTER_SHLIBS=	yes
WRKSRC?=	${WRKDIR}/${BROWSER}-v408.x86-unknown-freebsd
NO_BUILD=	Yes
STRIP=

BROWSER?=	communicator
BROWSER_VER=	4.08
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR=	lib/netscape
BINDIR=		${PREFIX}/bin
INFILE_HEAD?=	'Communicator,4.08.0.98306'
WRAPPER_TEMPLATE= ${MASTERDIR}/files/netscape.sh
MAILCAP=	${MASTERDIR}/files/mailcap

PLIST_SUB=	BROWSER=${BROWSER} BROWSER_VER=${BROWSER_VER} \
		NSUBDIR=${NSUBDIR}

.if defined(USE_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.3.2-unix-x86.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

.SILENT:

.if !defined(USE_128BIT)
pre-extract:
	${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
.endif

do-configure:
	${SED}	-e "s;@PREFIX@;${PREFIX};g" -e "s;@NSUBDIR@;${NSUBDIR};g" \
		-e "s;@BROWSER@;${BROWSER};g" \
		-e "s;@BROWSER_VER@;${BROWSER_VER};g" \
		${WRAPPER_TEMPLATE} >${WRKSRC}/netscape
	chmod +x ${WRKSRC}/netscape
	${ECHO} -n ${INFILE_HEAD},${NDIR} >${WRKSRC}/infile

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	${MKDIR} ${NDIR}/java/classes
	${INSTALL_DATA} ${WRKSRC}/*.jar ${NDIR}/java/classes
	${INSTALL_PROGRAM} ${WRKSRC}/vreg ${NDIR}
	for i in ${WRKSRC}/*.nif; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $${i} ${EXTRACT_AFTER_ARGS} -C ${NDIR}; \
	done
	${WRKSRC}/vreg ${NDIR}/registry ${WRKSRC}/infile
	${MV} -f ${NDIR}/netscape ${NDIR}/${BROWSER}-${BROWSER_VER}.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape \
		${BINDIR}/${BROWSER}-${BROWSER_VER}
	${LN} -sf ${BROWSER}-${BROWSER_VER} ${BINDIR}/${BROWSER}-4
	${LN} -sf ${BROWSER}-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
		${INSTALL_DATA} ${MAILCAP} ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
.if (${BROWSER} == "communicator")
	tar zxf ${DISTDIR}/${AUTOADMIN} -C ${NDIR}
.endif
.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
	cd ${WRKDIR}/Fortify-1.3.2-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no ; ${ECHO} no) \
		| ./Fortify.sh ${NDIR}/${BROWSER}-${BROWSER_VER}.bin
.endif
	chown -R bin.bin ${NDIR}

post-install:
	${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
