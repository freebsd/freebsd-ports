# New ports collection makefile for:	netscape (navigator only)
# Version required:     4.04
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.13 1997/11/20 15:48:24 asami Exp $
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

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv -f ${NDIR}/netscape ${NDIR}/navigator-4.04.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/navigator-4.04
	ln -sf navigator-4.04 ${BINDIR}/navigator-4
	ln -sf navigator-4 ${BINDIR}/netscape
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/movemail-src
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
