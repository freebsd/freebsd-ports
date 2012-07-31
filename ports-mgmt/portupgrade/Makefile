# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	2.4.9.7
PORTEPOCH=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF/portupgrade/pkgtools/dist/ \
		http://mirror.shatow.net/freebsd/pkgtools/
DISTNAME=	pkgtools-${PORTVERSION}

MAINTAINER=	bryan@shatow.net
COMMENT=	FreeBSD ports/packages administration and management tool suite

LICENSE=	BSD

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	DOCS DB_OVERRIDE
OPTIONS_SINGLE=	DB_OVERRIDE
OPTIONS_SINGLE_DB_OVERRIDE=	BDB4 BDB1
OPTIONS_DEFAULT=	DB_OVERRIDE BDB4 DOCS
DB_OVERRIDE_DESC=	Override DB backend instead of default DBM
BDB1_DESC=	Use Berkeley DB 1
BDB4_DESC=	Use Berkeley DB >=2

CONFLICTS_INSTALL=	portupgrade-devel-*

USE_BZIP2=	yes
USE_RUBY=	yes

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

.include <bsd.port.pre.mk>

INSTALL_TARGET=		install
.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=	install-doc
.endif

.if ${PORT_OPTIONS:MBDB4}
# For PKG_DBDRIVER={bdb_btree,bdb_hash}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
.elif ${PORT_OPTIONS:MBDB1}
# For PKG_DBDRIVER={bdb1_btree,bdb1_hash}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb1.so:${PORTSDIR}/databases/ruby-bdb1
.endif

# parsedate is needed for date globbing
.if ${RUBY_VER} == 1.9
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/parsedate.rb:${PORTSDIR}/devel/ruby-date2
.endif

pre-extract:
.if exists(${RUBY_SITEARCHLIBDIR}/bdb.so) && ${PORT_OPTIONS:MBDB1}
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG} "BDB1 is defined but databases/ruby-bdb port installed."
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
