# New ports collection makefile for:	mozilla
# Version required:	0.0
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $Id: Makefile,v 1.4 1998/03/11 00:01:05 eivind Exp $
#

DISTNAME=	unix
PKGNAME=	mozilla-1998-03-31
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cdrom.com/pub/mozilla/1998-03-31/ \
		ftp://ftp.bitcon.no/pub/www/mozilla/mozilla/1998-03-31/ \
		ftp://ftp.mozilla.org/pub/mozilla/1998-03-31/

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/ns
USE_GMAKE=	yes
NO_INSTALL_MANPAGES=yes
DIST_SUBDIR=	mozilla
MAKE_ENV=	NO_SECURITY=1 MOZ_MEDIUM=1 MOZILLA_CLIENT=1 NO_MDUPDATE=1 \
	LD_LIBRARY_PATH=${LOCALBASE}/lib
REQUIRES_MOTIF=	yes

OSNAME=	`uname -s`
OSVER=	`uname -r | ${SED} 's/-.*//'`
OBJDIR=	${WRKSRC}/dist/${OSNAME}${OSVER}_DBG.OBJ

do-install:
	@${MKDIR} ${PREFIX}/lib/mozilla/bin
	@tar -cf - --dereference -C ${OBJDIR}/bin bsdecho mozilla-export \
		nsinstall vreg | tar -xf - -C ${PREFIX}/lib/mozilla/bin
	@chmod 755 ${PREFIX}/lib/mozilla/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin
	@if [ ! -f ${PREFIX}/lib/mozilla/mailcap ] ; then \
		${INSTALL_DATA} ${FILESDIR}/mailcap ${PREFIX}/lib/mozilla ; \
	fi
	@strip ${PREFIX}/lib/mozilla/bin/mozilla-export
	@chown -R bin.bin ${PREFIX}/lib/mozilla

.include <bsd.port.mk>
