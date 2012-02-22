# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	9999
PORTREVISION=	0
PORTEPOCH=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/stass/pkgtools/tarball
PKGNAMESUFFIX=	-devel
DISTNAME=	pkgtools-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD ports/packages management tool (devel version)

CONFLICTS_INSTALL=	portupgrade-[0-9]*

FETCH_DEPENDS=	git:${PORTSDIR}/devel/git
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

MANUAL_PACKAGE_BUILD=	troubles with distfile cache on pointyhat

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
NO_CHECKSUM=	yes
GIT_REPO_URL=	git@github.com:stass/pkgtools.git

EXAMPLESDIR=	${PREFIX}/share/examples/pkgtools
DOCSDIR=	${PREFIX}/share/doc/pkgtools

INSTALL_TARGET=		install
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install-doc
.endif

do-fetch:
	@${MKDIR} ${_DISTDIR}/portupgrade
	@(head=`git ls-remote -h ${GIT_REPO_URL} | \
	    ${GREP} heads/master | ${AWK} '{print $$1}'`; \
	    if [ ! -f "${_DISTDIR}/portupgrade/pkgtools-$${head}.tar.gz" ]; then \
	    ${SETENV} ${FETCH_ENV} ${FETCH_BINARY} -m -o \
	    "${_DISTDIR}/portupgrade/pkgtools-$${head}.tar.gz" ${MASTER_SITES}/master \
	    && ln -sf "${_DISTDIR}/portupgrade/pkgtools-$${head}.tar.gz" \
	    "${_DISTDIR}/portupgrade/latest"; fi)

do-extract:
	${MKDIR} ${WRKSRC}
	@tar -C ${WRKSRC}/ --strip-components 1 -xf ${_DISTDIR}/portupgrade/latest

post-patch:	.SILENT
	${REINPLACE_CMD} '/PREFIX/s:\(=[[:space:]]*\)\(.*/usr/local\):\1ENV["LOCALBASE"] || \2:' \
		${WRKSRC}/lib/pkgdb.rb ${WRKSRC}/lib/pkgtools.rb

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi
	${MKDIR} ${PREFIX}/lib/compat/pkg

.include <bsd.port.mk>
