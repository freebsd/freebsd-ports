# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	portupgrade
PORTVERSION=	20150514
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		LOCAL/bdrewery/${PORTNAME}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	FreeBSD ports/packages management tool (devel version)

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL=	portupgrade-[0-9]*

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	2.4.13-7-g47dfa22

DIST_SUBDIR=	${PORTNAME}
USE_RUBY=	yes
USE_LDCONFIG=	${PREFIX}/lib/compat/pkg
MAKE_ARGS=	PREFIX="${PREFIX}" RUBY="${RUBY}" \
		RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" MKDIR="${MKDIR}"

EXAMPLESDIR=	${PREFIX}/share/examples/pkgtools
DOCSDIR=	${PREFIX}/share/doc/pkgtools

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

INSTALL_TARGET=		install
.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=	install-doc
.endif

# For PKG_DBDRIVER={bdb_btree,bdb_hash}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bdb.so:databases/ruby-bdb

regression-test: patch
	cd ${WRKSRC} && ${MAKE} test

post-patch:	.SILENT
	REVISION=`readlink "${_DISTDIR}/portupgrade/latest" | ${SED} -E -e 's,.*pkgtools-(.*).tar.gz,\1,g'` && ${SED} -E -e "s,%%DATE%%,${PORTVERSION},g;s,%%REVISION%%,$${REVISION},g" \
	    ${WRKSRC}/lib/pkgtools/revision.rb.in > ${WRKSRC}/lib/pkgtools/revision.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/compat/pkg

.include <bsd.port.post.mk>
