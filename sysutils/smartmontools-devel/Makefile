# New ports collection makefile for:   smartmontools
# Date created:        12 October 2003
# Whom:                Eduard Martinescu
#
# $FreeBSD$
#

PORTNAME=	smartmontools
PORTVERSION=	5.38.r${SVNREVISION}
CATEGORIES=	sysutils
MASTER_SITES=	http://wisnia21.freeshell.org/f/ports/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	mwisnicki+freebsd@gmail.com
COMMENT=	S.M.A.R.T. disk monitoring tools (SVN snapshot)

SVNREVISION=	2874

CONFLICTS=	smartmontools-[0-9]*

USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} --enable-sample --with-initscriptdir=no

SUB_FILES=	pkg-message smart
USE_RC_SUBR=	smartd

MAN5=		smartd.conf.5
MAN8=		smartd.8 smartctl.8

CFLAGS:=	${CFLAGS:S/-O2/-O/}

post-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/smart ${PREFIX}/etc/periodic/daily/smart
	@${CAT} ${PKGMESSAGE}

x-maintainer-make-snapshot:
	svn export -r${SVNREVISION} \
		https://smartmontools.svn.sourceforge.net/svnroot/smartmontools/trunk/smartmontools \
		${DISTNAME}
	${TAR} -cjvf ${DISTNAME}.tar.bz2 ${DISTNAME}
	${RM} -rf ${DISTNAME}

.include <bsd.port.mk>
