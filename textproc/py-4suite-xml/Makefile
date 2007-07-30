# New ports collection makefile for:	py-4Suite-XML
# Date created:				26 October 2005
# Whom:					Mike Brown <mike@skew.org>
#
# $FreeBSD$
#

PORTNAME=	4Suite-XML
PORTVERSION=	1.0
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.4suite.org/pub/4Suite/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	foursuite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mike@skew.org
COMMENT=	A collection of Python tools for XML processing

USE_BZIP2=	yes
REINPLACE_ARGS=	-i "" -E
USE_PYTHON=	2.2.1+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	4Suite-XML
PYDISTUTILS_PKGVERSION=	1.0

CONFLICTS=	py*-4suite-[01]*

# xml.sax.make_parser() needs to return an Expat parser in order to
# support generation of API docs in XML format. --with/without-docs
# only affects whether the XML is rendered to other formats and
# installed.  PyExpat is already installed in python-2.3.2_2 and up.
BUILD_DEPENDS=	${PYEXPAT}

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
.endif

.include <bsd.port.post.mk>
