# New ports collection makefile for:	netscape (navigator only)
# Version required:     4.08
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.35 1999/01/06 04:18:14 simokawa Exp $
#

DISTNAME=       netscape-navigator-4.08
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/4.08/english/unix/unsupported/freebsd/navigator_standalone/
DISTFILES=	navigator-v408-export.x86-unknown-freebsd.tar.gz

MAINTAINER=     sada@FreeBSD.ORG

Y2K=		http://home.netscape.com/products/year2000/faq/client.html

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/navigator-v408.x86-unknown-freebsd
NO_BUILD=       Yes
STRIP=

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin
INFILE_HEAD=	'Navigator,4.08.0.98306,'

.if defined(USE_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.3.2-unix-x86.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

.if !defined(USE_128BIT)
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
.endif

do-configure:
	${ECHO} -n ${INFILE_HEAD} > ${WRKSRC}/infile
	${ECHO} ${NDIR} >> ${WRKSRC}/infile
	${SED} -e "s;@X11BASE@;${X11BASE};g" -e "s;@PREFIX@;${PREFIX};g" \
		${FILESDIR}/netscape.sh >${WRKSRC}/netscape
	chmod +x ${WRKSRC}/netscape

do-install:
	${MKDIR} ${NDIR}/java/classes
	${INSTALL_DATA} ${WRKSRC}/*.jar ${NDIR}/java/classes
	${INSTALL_PROGRAM} ${WRKSRC}/vreg ${NDIR}
	for i in ${WRKSRC}/*.nif; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $${i} -C ${NDIR}; \
	done
	${WRKSRC}/vreg ${NDIR}/registry ${WRKSRC}/infile
	${MV} -f ${NDIR}/netscape ${NDIR}/navigator-4.08.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/navigator-4.08
	ln -sf navigator-4.08 ${BINDIR}/navigator-4
	ln -sf navigator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
.if defined(USE_128BIT)
	cd ${WRKDIR}/Fortify-1.3.2-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no ; ${ECHO} no) | ./Fortify.sh ${NDIR}/navigator-4.08.bin
.endif
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
