# New ports collection makefile for:	netscape (full communicator beta)
# Version required:     4.5
# Date created:         24 Feb 1997
# Whom:                 thepish
#
# $Id: Makefile,v 1.25 1998/10/07 13:44:16 obrien Exp $
#

DISTNAME=	communicator-v45-export.x86-unknown-freebsd
PKGNAME=	netscape-communicator-4.5
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.5/english/unix/unsupported/freebsd/complete_install/

MAINTAINER=     thepish@FreeBSD.ORG

NO_LATEST_LINK=	yes
WRKSRC=         ${WRKDIR}/communicator-v45.x86-unknown-freebsd
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape.45
BINDIR=		${PREFIX}/bin

pre-extract:
.if defined(USE_128BIT)
	@${ECHO} "Sorry Fortify do not provide support for pre-release netscape versions"
.endif

.if !defined(MULTIVERSION)
		@${ECHO} "you can define MULTIVERSION to install the script which runs communicator-v45"
		@${ECHO} "as ${BINDIR}/communicator-4.5 rather than ${BINDIR}/netscape."
		@${ECHO} "You may find this useful if you want to run the stable and pre release versions"
		@${ECHO} "concurrently."
.endif


do-install:
	cd ${WRKSRC} && \
	  yes "" | LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/communicator-4.5.bin
.if defined(MULTIVERSION)
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.5
.else
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
.endif
	if [ ! -f ${NDIR}/mailcap ] ; then \
	  ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
	chown -R root.wheel ${NDIR}

.include <bsd.port.mk>
