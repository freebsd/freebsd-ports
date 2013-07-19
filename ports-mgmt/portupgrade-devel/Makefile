# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	portupgrade
PORTVERSION=	20130718
PORTEPOCH=	3
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH \
		http://mirror.shatow.net/freebsd/pkgtools/
PKGNAMESUFFIX=	-devel
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	FreeBSD ports/packages management tool (devel version)

LICENSE=	BSD

CONFLICTS_INSTALL=	portupgrade-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	portupgrade
GH_COMMIT=	633cdd7
GH_TAGNAME=	${GH_COMMIT}

DIST_SUBDIR=	${PORTNAME}
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
		portsvnweb.1 \
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

regression-test: patch
	cd ${WRKSRC} && ${MAKE} test

post-patch:	.SILENT
	REVISION=`readlink "${_DISTDIR}/portupgrade/latest" | ${SED} -E -e 's,.*pkgtools-(.*).tar.gz,\1,g'` && ${SED} -E -e "s,%%DATE%%,${PORTVERSION},g;s,%%REVISION%%,$${REVISION},g" \
	    ${WRKSRC}/lib/pkgtools/revision.rb.in > ${WRKSRC}/lib/pkgtools/revision.rb

post-install:
	if [ ! -f ${PREFIX}/etc/pkgtools.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgtools.conf.sample ${PREFIX}/etc/pkgtools.conf; \
	fi
	${MKDIR} ${PREFIX}/lib/compat/pkg

.include <bsd.port.post.mk>
