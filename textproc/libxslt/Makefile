# New ports collection makefile for:	libxslt
# Date created:				9th February 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxslt
PORTVERSION=	1.1.2
PORTREVISION=	3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The XSLT C library for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget libxml2
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN3=		libexslt.3 libxslt.3
MAN1=		xsltproc.1

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON:="@comment "
PKGNAMESUFFIX=	-nopython
.endif

.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--with-mem-debug
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libxslt has several tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_PYTHON=yes		Turns off python support"
	@${ECHO_MSG} "	WITH_MEM_DEBUG=yes		Turns on memory debugging"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|[$$](bindir)/xsltproc|../xsltproc/xsltproc|g ; \
		s|[$$](bindir)/xmllint|../xmllint/xmllint|g' \
		${WRKSRC}/doc/Makefile.in

.if !defined(WITHOUT_PYTHON)
post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
.endif

.include <bsd.port.mk>
