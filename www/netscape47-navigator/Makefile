# New ports collection makefile for:	netscape (navigator only)
# Version required:     4.5
# Date created:         20 Sept 1998
# Whom:                 brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.28 1998/11/19 21:57:42 billf Exp $
#

DISTNAME=       netscape-navigator-4.5
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.5/english/unix/unsupported/freebsd/navigator_standalone/
DISTFILES=      navigator-v45-export.x86-unknown-freebsd.tar.gz

MAINTAINER=     ports@FreeBSD.ORG

NO_LATEST_LINK=	yes
WRKSRC=         ${WRKDIR}/navigator-v45.x86-unknown-freebsd
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

.if defined(USE_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.3.0-unix-x86.tar.gz
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
	${MV} -f ${NDIR}/netscape ${NDIR}/navigator-4.5.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/navigator-4.5
	ln -sf navigator-4.5 ${BINDIR}/navigator-4
	ln -sf navigator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
.if defined(USE_128BIT)
	cd ${WRKDIR}/Fortify-1.3.0-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/navigator-4.5.bin
.endif
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
