# New ports collection makefile for:	py-4suite
# Date created:		16 March 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	4suite
PORTVERSION=	1.0.b1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.4suite.org/pub/4Suite/ \
		SF/foursuite/4Suite/1.0b1		

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	4Suite-1.0b1

MAINTAINER=	mike@skew.org
COMMENT=	A collection of Python tools for XML and RDF processing

USE_BZIP2=	yes
REINPLACE_ARGS=	-i "" -E
USE_PYTHON=	2.2-2.4
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	4Suite
PYDISTUTILS_PKGVERSION=	1.0b1

CONFLICTS=	py*-4Suite-1* py*-xml-0.7*

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	fails self-tests on 64-bit platforms

.include <bsd.port.pre.mk>

BINDIR=		bin
SYSCONFDIR=	etc/4Suite
LIBDIR=		lib/4Suite
LOCALSTATEDIR=	var/4Suite
DATADIR=	share/4Suite
DOCSDIR=	share/doc/4Suite
LOCALEDIR=	share/locale

PLIST_SUB+=	PACKAGE_DIR=Ft BINDIR=${BINDIR} SYSCONFDIR=${SYSCONFDIR} \
		LIBDIR=${LIBDIR} LOCALSTATEDIR=${LOCALSTATEDIR} \
		DATADIR=${DATADIR} DOCSDIR=${DOCSDIR} LOCALEDIR=${LOCALEDIR}

SUB_FILES=	pkg-message
SUB_LIST+=	PACKAGE_DIR=Ft BINDIR=${BINDIR} SYSCONFDIR=${SYSCONFDIR} \
		LIBDIR=${LIBDIR} LOCALSTATEDIR=${LOCALSTATEDIR} \
		DATADIR=${DATADIR} DOCSDIR=${DOCSDIR} LOCALEDIR=${LOCALEDIR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		DISTVERSION=${DISTVERSION}

PYDISTUTILS_CONFIGUREARGS=	--bindir=${PREFIX}/${BINDIR} \
				--sysconfdir=${PREFIX}/${SYSCONFDIR} \
				--libdir=${PREFIX}/${LIBDIR} \
				--localstatedir=${PREFIX}/${LOCALSTATEDIR} \
				--datadir=${PREFIX}/${DATADIR} \
				--docdir=${PREFIX}/${DOCSDIR} \
				--localedir=${PREFIX}/${LOCALEDIR} \
				--pythonlibdir=${PYTHON_SITELIBDIR}

.if defined(NOPORTDOCS)
PYDISTUTILS_BUILDARGS=		--without-docs
PYDISTUTILS_INSTALLARGS=	--without-docs
.else
PYDISTUTILS_BUILDARGS=		--with-docs
PYDISTUTILS_INSTALLARGS=	--with-docs
.if exists(${PYTHON_SITELIBDIR}/_bsddb.so) || exists(${PYTHON_SITELIBDIR}/bsddb3/_pybsddb.so)
PLIST_SUB+=	WITH_PYBSDDB=""
.else
PLIST_SUB+=	WITH_PYBSDDB="@comment "
.endif
.if exists(${PYTHON_SITELIBDIR}/_dbxml.so)
PLIST_SUB+=	WITH_PYBDBXML=""
.else
PLIST_SUB+=	WITH_PYBDBXML="@comment "
.endif
.endif

post-extract:
	@ ${REINPLACE_CMD} -e "s#'4ss.conf'#'4ss.conf.sample'#" \
		${WRKSRC}/packages/Server.pkg

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCSDIR}
.endif

.include <bsd.port.post.mk>
