# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	2.4.6
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	pkgtools-${DISTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	FreeBSD ports/packages administration and management tool suite

OPTIONS=	BDB4 "Use Berkeley DB >=2 as backend" on \
		BDB1 "Use Berkeley DB 1.85 as backend" off

CONFLICTS=	portupgrade-devel-*

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	optparse ruby18

USE_LDCONFIG=	${PREFIX}/lib/compat/pkg

MAKE_ARGS=	PREFIX="${PREFIX}" RUBY="${RUBY}"

MAN1=		pkg_deinstall.1 \
		pkg_fetch.1 \
		pkg_glob.1 \
		pkg_sort.1 \
		pkgdb.1 \
		pkgdu.1 \
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

EXAMPLESDIR=	${PREFIX}/share/examples/pkgtools
DOCSDIR=	${PREFIX}/share/doc/pkgtools

INSTALL_TARGET=		install
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install-doc
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_BDB4)
# For PKG_DBDRIVER={bdb_btree,bdb_hash}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
.endif
.if defined(WITH_BDB1) && !defined(WITH_BDB4)
# For PKG_DBDRIVER={bdb1_btree,bdb1_hash}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb1.so:${PORTSDIR}/databases/ruby-bdb1
.endif

pre-extract:
.if !defined(WITH_BDB4) && !defined(WITH_BDB1)
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG} "Neither WITH_BDB4 nor WITH_BDB1 are defined. Will use DBD driver."
	@${ECHO_MSG} "================================================================="
.endif
.if defined(WITH_BDB4) && defined(WITH_BDB1)
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG} "Both WITH_BDB4 and WITH_BDB1 are defined. Will use BDB4 driver."
	@${ECHO_MSG} "================================================================="
.elif defined(WITH_BDB1) && exists(${RUBY_SITEARCHLIBDIR}/bdb.so)
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG} "WITH_BDB1 is defined but ruby-bdb port installed."
	@${ECHO_MSG} "Remove ruby-bdb or redefine options."
	@${ECHO_MSG} "================================================================="
	@exit 1
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi
	${MKDIR} ${PREFIX}/lib/compat/pkg
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
