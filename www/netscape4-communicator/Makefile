# New ports collection makefile for:	netscape (full communicator version)
# Version required:     4.*
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.24 1998/11/19 05:17:40 obrien Exp $
#

DISTNAME=       netscape-communicator-4.07
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.07/development/english/unix/freebsd/professional_edition/
DISTFILES=      communicator-v407-export.x86-unknown-freebsd.tar.gz ${AUTOADMIN}
AUTOADMIN=      autoadmin-v407.x86-unknown-freebsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

BROKEN=		"'due to a lack of disk space, Netscape removed\
		${DISTNAME}'"

NO_FILTER_SHLIBS=	yes
WRKSRC=         ${WRKDIR}/communicator-v407.x86-unknown-freebsd
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
.endif

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv -f ${NDIR}/netscape ${NDIR}/communicator-4.07.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.07
	ln -sf communicator-4.07 ${BINDIR}/communicator-4
	ln -sf communicator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/movemail-src
	tar zxvf ${DISTDIR}/${AUTOADMIN} -C ${NDIR}
.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
	cd ${WRKDIR}/Fortify-1.3.0-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/communicator-4.07.bin
.endif
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
