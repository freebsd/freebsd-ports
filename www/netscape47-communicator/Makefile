# New ports collection makefile for:	netscape (full communicator version)
# Version required:     4.05
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.18 1998/04/02 22:47:52 ache Exp $
#

DISTNAME=       netscape-communicator-4.05
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.05/development/english/unix/freebsd/professional_edition/
DISTFILES=      communicator-v405-export.x86-unknown-freebsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/communicator-v405.x86-unknown-freebsd
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.2.2-unix.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

.if !defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
		@${ECHO} "and defining USA_RESIDENT to NO"
.endif

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv -f ${NDIR}/netscape ${NDIR}/communicator-4.05.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.05
	ln -sf communicator-4.05 ${BINDIR}/communicator-4
	ln -sf communicator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/movemail-src
.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
	cd ${WRKDIR}/Fortify-1.2.2-unix && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/communicator-4.05.bin
.endif
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
