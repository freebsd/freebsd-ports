# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	portupgrade
PORTVERSION=	2.4.11
PORTEPOCH=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF/portupgrade/pkgtools/dist/ \
		http://mirror.shatow.net/freebsd/pkgtools/ \
		LOCAL/bdrewery/pkgtools/
DISTNAME=	pkgtools-${PORTVERSION}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	FreeBSD ports/packages administration and management tool suite

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS

CONFLICTS_INSTALL=	portupgrade-devel-*

DIST_SUBDIR=	${PORTNAME}
USE_BZIP2=	yes
USE_RUBY=	yes

USE_LDCONFIG=	${PREFIX}/lib/compat/pkg

MAKE_ARGS=	PREFIX="${PREFIX}" RUBY="${RUBY}" RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" MKDIR="${MKDIR}"

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
		portcvsweb.1 portsvnweb.1 \
		portsdb.1 ports_glob.1
MANCOMPRESSED=	maybe

EXAMPLESDIR=	${PREFIX}/share/examples/pkgtools
DOCSDIR=	${PREFIX}/share/doc/pkgtools

.include <bsd.port.pre.mk>

INSTALL_TARGET=		install
.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=	install-doc
.endif

# Reported that ruby-bdb is BROKEN with 2.0
.if ${RUBY_VER} != 2.0
# For PKG_DBDRIVER={bdb_btree,bdb_hash}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
.endif

# parsedate is needed for date globbing
.if ${RUBY_VER} == 1.9
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/parsedate.rb:${PORTSDIR}/devel/ruby-date2
.endif

# Need to install working script(1)
.if ${OSVERSION} < 801000
PLIST_SUB+=	SCRIPT=""
MAKE_ENV+=	NEED_COMPAT_SCRIPT=yes
.else
PLIST_SUB+=	SCRIPT="@comment "
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi
	${MKDIR} ${PREFIX}/lib/compat/pkg
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
