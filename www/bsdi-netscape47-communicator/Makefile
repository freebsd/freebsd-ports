# New ports collection makefile for:	netscape (full communicator beta)
# Version required:     4.5
# Date created:         24 Feb 1997
# Whom:                 thepish
#
# $Id: Makefile,v 1.24 1998/09/03 08:21:40 asami Exp $
#

DISTNAME=       communicator-v45b2-export.x86-unknown-freebsd
PKGNAME=       netscape-communicator-4.5b2
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.5/4.5_PR2/english/unix/unsupported/freebsd/professional_edition/

MAINTAINER=     thepish@FreeBSD.ORG

NO_LATEST_LINK=	yes
WRKSRC=         ${WRKDIR}/communicator-v45b2.x86-unknown-freebsd
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape.45
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
	mv -f ${NDIR}/netscape ${NDIR}/communicator-4.5.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.5
	#ln -sf communicator-4.5 ${BINDIR}/communicator-4
	#ln -sf communicator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/movemail-src
.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
	cd ${WRKDIR}/Fortify-1.2.2-unix && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/communicator-4.5.bin
.endif
	chown -R root.wheel ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
