# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	20020920
CATEGORIES=	sysutils
MASTER_SITES=	http://www.iDaemons.org/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	pkgtools-${DISTVERSION}

DISTVERSION=	20020805

.if ${DISTVERSION} != ${PORTVERSION}
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	${DISTNAME}-20020830.diff.bz2 \
		pkgtools-20020830-20020902.diff.bz2 \
		pkgtools-20020902-${PORTVERSION}.diff.bz2
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb1.so:${PORTSDIR}/databases/ruby-bdb1 \
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

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.7
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/features/ruby18/file_ruby18.so:${PORTSDIR}/lang/ruby16-shim-ruby18
.endif

pre-install:
.if !defined(NOPORTDOCS)
# Cope with a bug in CURRENT's bsd.*.mk infrastructure
	${MKDIR} ${PREFIX}/share/examples/pkgtools/bash
	${MKDIR} ${PREFIX}/share/examples/pkgtools/tcsh
	${MKDIR} ${PREFIX}/share/zsh/site-functions
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi

.include <bsd.port.post.mk>
