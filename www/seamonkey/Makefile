# New ports collection makefile for:	mozilla
# Version required:	1998-04-29
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $Id: Makefile,v 1.25 1998/05/02 17:49:09 jseger Exp $
#

DISTNAME=	unix-19980429
PKGNAME=	mozilla-1998.04.29
CATEGORIES=	www
MASTER_SITES=	ftp://mirror.neosoft.com/pub/mozilla/mozilla/source/ \
		ftp://ftp.bitcon.no/pub/www/mozilla/mozilla/source/ \
		ftp://ftp.mozilla.org/pub/mozilla/source/

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/`${ECHO} ${DISTNAME} | ${SED} 's/unix-//'`/mozilla
USE_GMAKE=	yes
DIST_SUBDIR=	mozilla
MAKE_ENV=	NO_SECURITY=1 MOZ_MEDIUM=1 MOZILLA_CLIENT=1 NO_MDUPDATE=1 \
	BUILD_OPT=1 NO_NETSCAPE_STATIC=1 LD_LIBRARY_PATH=${LOCALBASE}/lib
REQUIRES_MOTIF=	yes

OSNAME=	`uname -s`
OSVER=	`uname -r | ${SED} 's/-.*//'`
OBJDIR=	${WRKSRC}/dist/${OSNAME}${OSVER}_OPT.OBJ

do-install:
	@${MKDIR} ${PREFIX}/lib/mozilla/bin
	@cd ${OBJDIR}/bin && tar -chf - bsdecho lib* moz-export \
		nsinstall vreg | tar -xf - -C ${PREFIX}/lib/mozilla/bin
	@chmod 755 ${PREFIX}/lib/mozilla/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin
	@if [ ! -f ${PREFIX}/lib/mozilla/mailcap ] ; then \
		${INSTALL_DATA} ${FILESDIR}/mailcap ${PREFIX}/lib/mozilla ; \
	fi
	@strip ${PREFIX}/lib/mozilla/bin/moz-export
	@chown -R bin.bin ${PREFIX}/lib/mozilla

.include <bsd.port.mk>
