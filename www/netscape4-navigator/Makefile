# New ports collection makefile for:	netscape (navigator only)
# Version required:     4.04
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.14 1998/01/26 09:55:56 vanilla Exp $
#

DISTNAME=       netscape-navigator-4.04
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.04/development/english/unix/freebsd/navigator_standalone/
DISTFILES=      navigator-v404-export.x86-unknown-freebsd.tar.gz

MAINTAINER=     asami@FreeBSD.ORG

NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

.if defined(USE_128BIT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.1.5-unix.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/navigator-4.04.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/navigator-4.04
	ln -sf navigator-4.04 ${BINDIR}/navigator-4
	ln -sf navigator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
	chown -R bin.bin ${NDIR}
.if defined(USE_128BIT) && ${USA_RESIDENT} == NO
	cd ${WRKSRC}/Fortify-1.1.5-unix && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/navigator-4.04.bin
.endif

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
