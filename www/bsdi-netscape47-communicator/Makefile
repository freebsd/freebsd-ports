# New ports collection makefile for:	netscape (communicator suite)
# Version required:     4.5
# Date created:         24 Feb 1997
# Whom:                 thepish
#
# $Id: Makefile,v 1.36 1999/01/06 04:18:16 simokawa Exp $
#

DISTNAME=	communicator-v45-export.x86-unknown-freebsd
PKGNAME=	netscape-communicator-4.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/4.5/english/unix/unsupported/freebsd/complete_install/
# DISTFILES must be set to begin with so USE_128BIT can add on to it.
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	thepish@FreeBSD.ORG

Y2K=		http://home.netscape.com/products/year2000/faq/client.html

ONLY_FOR_ARCHS=	i386

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/communicator-v45.x86-unknown-freebsd
NO_BUILD=	Yes
PLIST_SUB=	NDIRBASE=${NDIRBASE}
NO_FILTER_SHLIBS=yes

NDIRBASE=	netscape-4.5
NDIR=		${PREFIX}/${NDIRBASE}
BINDIR=		${PREFIX}/bin
NBIN=		communicator-4.5.bin

.if defined(USE_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.3.2-unix-x86.tar.gz
RESTRICTED=	"Contains strong cryptography"
.else
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
.endif	# USE_128BIT

post-configure:
	${SED}	-e "s;@NDIR@;${NDIR};g" \
		-e "s;@NBIN@;${NBIN};g" \
		${FILESDIR}/netscape.sh >${WRKSRC}/netscape

do-install:
	cd ${WRKSRC} && \
		yes "" | LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/communicator-4.5.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.5
	${LN} -sf communicator-4.5 ${BINDIR}/communicator-4
	${LN} -sf communicator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
		${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
.if defined(USE_128BIT)
	cd ${WRKDIR}/Fortify-1.3.2-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no ; ${ECHO} no) | ./Fortify.sh ${NDIR}/communicator-4.5.bin
.endif
	chown -R ${BINOWN}.${BINGRP} ${NDIR}

.include <bsd.port.mk>
