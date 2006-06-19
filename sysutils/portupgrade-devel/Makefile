# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	2.1.1
PORTEPOCH=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://sunner.elcomnet.ru/~sem/
MASTER_SITE_SUBDIR=	sem
DISTNAME=	pkgtools-${DISTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	FreeBSD ports/packages administration and management tool suite

OPTIONS=	BDB4 "Use Berkeley DB >=2 as backend. (Use BDB 1.85 if off)" off

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	optparse ruby18
USE_PERL5_RUN=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat/pkg
USE_LDCONFIG=	${PREFIX}/lib/compat/pkg

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
.include "${PORTSDIR}/misc/ldconfig_compat/bsd.ldconfig.mk"

.if defined(WITH_BDB4)
# For PKG_DBDRIVER={bdb_btree,bdb_hash,bdb}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
.else
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb1.so:${PORTSDIR}/databases/ruby-bdb1
.endif

post-install: install-ldconfig-file
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi

.include <bsd.port.post.mk>
