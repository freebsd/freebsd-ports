# New ports collection makefile for:	netscape
# Version required:     4.04
# Date created:         24 Feb 1997
# Whom:                 ache
#
# Note: you can make the standalone navigator version by typing
#       make NAVIGATOR=yes
#
# $Id: Makefile,v 1.9 1997/11/14 13:45:39 ache Exp $
#

DISTNAME=       netscape-4.04
CATEGORIES=	www
.if !defined(NAVIGATOR)
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.04/development/english/unix/freebsd/professional_edition/
DISTFILES=      communicator-v404-export.x86-unknown-freebsd.tar.gz
.else
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.04/development/english/unix/freebsd/navigator_standalone/
DISTFILES=      navigator-v404-export.x86-unknown-freebsd.tar.gz
.endif

# responsible for communicator only
MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software"

NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv ${NDIR}/netscape ${NDIR}/netscape.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/movemail-src
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
