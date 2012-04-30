# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	20120429
PORTEPOCH=	3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://github.com/pkgtools/pkgtools/tarball/${GITVERSION}/ \
		http://www.shatow.net/freebsd/
PKGNAMESUFFIX=	-devel
DISTNAME=	pkgtools-pkgtools-${GITVERSION}

MAINTAINER=	bryan@shatow.net
COMMENT=	FreeBSD ports/packages management tool (devel version)

LICENSE=	BSD

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

CONFLICTS_INSTALL=	portupgrade-[0-9]*

FETCH_ARGS=	-Fpr
GITVERSION=	0449e52

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

INSTALL_TARGET=		install
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install-doc
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} '/PREFIX/s:\(=[[:space:]]*\)\(.*/usr/local\):\1ENV["LOCALBASE"] || \2:' \
		${WRKSRC}/lib/pkgdb.rb ${WRKSRC}/lib/pkgtools.rb

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi
	${MKDIR} ${PREFIX}/lib/compat/pkg

.include <bsd.port.mk>
