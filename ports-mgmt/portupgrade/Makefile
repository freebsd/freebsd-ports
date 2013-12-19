# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	portupgrade
PORTVERSION=	2.4.12
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

MAKE_ARGS=	PREFIX="${PREFIX}" RUBY="${RUBY}" \
		RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" MKDIR="${MKDIR}"

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

# Need to install working script(1)
.if ${OSVERSION} < 801000
PLIST_SUB+=	SCRIPT=""
MAKE_ENV+=	NEED_COMPAT_SCRIPT=yes
.else
PLIST_SUB+=	SCRIPT="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/compat/pkg

.include <bsd.port.post.mk>
