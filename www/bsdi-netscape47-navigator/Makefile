# New ports collection makefile for:	netscape (navigator only)
# Version required:     4.05
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.19 1998/04/03 00:23:42 asami Exp $
#

DISTNAME=       netscape-navigator-4.05
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.05/development/english/unix/freebsd/navigator_standalone/
DISTFILES=      navigator-v405-export.x86-unknown-freebsd.tar.gz

MAINTAINER=     asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/navigator-v405.x86-unknown-freebsd
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.2.2-unix.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

.if !defined(USE_128BIT)
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
		@${ECHO} "and defining USA_RESIDENT to NO"
.endif

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/navigator-4.05.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/navigator-4.05
	ln -sf navigator-4.05 ${BINDIR}/navigator-4
	ln -sf navigator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
	cd ${WRKDIR}/Fortify-1.2.2-unix && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/navigator-4.05.bin
.endif
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
