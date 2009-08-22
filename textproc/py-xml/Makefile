# Ports collection Makefile for:	PyXML
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		xml
PORTVERSION=		0.8.4
PORTREVISION=		2
CATEGORIES=		textproc python
MASTER_SITES=		SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		PyXML-${PORTVERSION}

MAINTAINER=		mike@skew.org
COMMENT=		PyXML: Python XML library enhancements

USE_PYTHON=		2.1+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyXML

.include <bsd.port.pre.mk>

CPIOARGS=		--quiet -pdum -R
DOCSDIR=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=		${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=		PACKAGE_DIR=_xmlplus

# PyXML's XPath support for minidom (xml.xpath) is functional and is
# installed by default, unless WITHOUT_XPATH is defined.
#
# PyXML's XSLT support for minidom (xml.xslt) is experimental, and may
# render PyXML incompatible with modern versions of 4Suite. Therefore,
# this port will not install it by default, unless WITH_XSLT is defined.
# These defaults are the same as when PyXML is installed independently.
#
# WITHOUT_XPATH is ignored if WITH_XSLT is defined.
#
# There are no mature XSLT processors that can operate directly on
# minidom documents, but such documents can be converted to formats
# that are supported. 4Suite, for example, can convert a DOM directly
# to a Domlette, and other processors can make use of the serialized
# form of the document.
#
.if defined(WITH_XSLT)
PYDISTUTILS_BUILDARGS+=	--with-xslt
PYDISTUTILS_INSTALLARGS+=	--with-xslt
PLIST_SUB+=	XPATH=""
PLIST_SUB+=	XSLT=""
.elif defined(WITHOUT_XPATH)
PYDISTUTILS_BUILDARGS+=	--without-xpath --without-xslt
PYDISTUTILS_INSTALLARGS+=	--without-xpath --without-xslt
PLIST_SUB+=	XPATH="@comment "
PLIST_SUB+=	XSLT="@comment "
.else
PYDISTUTILS_BUILDARGS+=	--with-xpath --without-xslt
PYDISTUTILS_INSTALLARGS+=	--with-xpath --without-xslt
PLIST_SUB+=	XPATH=""
PLIST_SUB+=	XSLT="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ANNOUNCE CREDITS LICENCE README* TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ cd ${WRKSRC}/doc && ${FIND} * \
	  | ${CPIO} ${CPIOARGS} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ cd ${WRKSRC} && ${FIND} demo test \
	  | ${CPIO} ${CPIOARGS} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
