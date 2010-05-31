# New ports collection makefile for:	gnome-doc-utils
# Date created:				11 November 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/gnome-doc-utils/Makefile,v 1.82 2010/04/27 00:16:27 kwm Exp $
#

PORTNAME=	gnome-doc-utils
PORTVERSION=	0.20.1
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME doc utils

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2 \
    		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2 \
		${LOCALBASE}/share/xml/docbook/4.3/catalog.xml:${PORTSDIR}/textproc/docbook-xml-430 \
		${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:${PORTSDIR}/textproc/docbook-xml-440

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehier gnomehack libxslt intlhack
USE_PYTHON=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-omf-dir=${PREFIX}/share/omf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xml2po.1

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}/xml2po
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}/xml2po/modes

.include <bsd.port.mk>
