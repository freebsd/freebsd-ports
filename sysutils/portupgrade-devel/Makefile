# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	20020225
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.iDaemons.org/distfiles/
MASTER_SITE_SUBDIR=	knu
DISTNAME=	pkgtools-20020204

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	pkgtools-20020204-20020218.diff.bz2 \
		pkgtools-20020218-20020220.diff.bz2 \
		pkgtools-20020220-20020220.1.diff.bz2 \
		pkgtools-20020220.1-20020225.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse \
		${RUBY_SITEARCHLIBDIR}/fnmatch.so:${PORTSDIR}/devel/ruby-fnmatch \
		${RUBY_SITEARCHLIBDIR}/bdb1.so:${PORTSDIR}/databases/ruby-bdb1 \
		${LOCALBASE}/sbin/pkg_tarup:${PORTSDIR}/sysutils/pkg_tarup
# For PKG_DBDRIVER={bdb_btree,bdb_hash,bdb}
#		${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

USE_BZIP2=	yes
USE_RUBY=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" RUBY="${RUBY}"

MAN1=		pkg_deinstall.1 \
		pkg_fetch.1 \
		pkg_glob.1 \
		pkg_sort.1 \
		pkgdb.1 \
		portcvsweb.1 \
		portsclean.1 \
		portsdb.1 \
		portupgrade.1 \
		portversion.1
MAN5=		pkgtools.conf.5
MLINKS=		pkgdb.1 pkg_which.1 \
		portupgrade.1 portinstall.1 \
		portsdb.1 ports_glob.1
MANCOMPRESSED=	maybe

INSTALL_TARGET=		install
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install-doc
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi

.include <bsd.port.mk>
