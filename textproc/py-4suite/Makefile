# New ports collection makefile for:	py-4suite
# Date created:		16 March 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	4suite
PORTVERSION=	1.0.b1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.4suite.org/pub/4Suite/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	foursuite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	4Suite-1.0b1

MAINTAINER=	mike@skew.org
COMMENT=	A collection of Python tools for XML and RDF processing

USE_BZIP2=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i "" -E
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

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

post-extract:
	@ ${REINPLACE_CMD} -e "s#'4ss.conf'#'4ss.conf.sample'#" \
		${WRKSRC}/packages/Server.pkg

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCSDIR}
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
