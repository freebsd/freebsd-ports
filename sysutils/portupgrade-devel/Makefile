# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	20040113
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	pkgtools-${DISTVERSION}

DISTVERSION=	20030427

.if ${DISTVERSION} != ${PORTVERSION}
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	${DISTNAME}-20030723.diff.bz2 \
		pkgtools-20030723-${PORTVERSION}.diff.bz2
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	knu@FreeBSD.org
COMMENT=	FreeBSD ports/packages administration and management tool suite

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb1.so:${PORTSDIR}/databases/ruby-bdb1
# For PKG_DBDRIVER={bdb_btree,bdb_hash,bdb}
#		${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	optparse ruby18

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

.include <bsd.port.pre.mk>

# pkg_create(1) must support -b. (4.5-RELEASE or later)
# XXX: PKG_CMD is not defined yet..
PKG_CREATE_OK!=	/usr/sbin/pkg_create 2>&1 | ${GREP} ' -b ' || ${TRUE}
.if empty(PKG_CREATE_OK)
IGNORE=	pkg_create does not support -b.  Please update /usr/sbin/pkg_* to those of the latest RELENG_4
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi

.include <bsd.port.post.mk>
