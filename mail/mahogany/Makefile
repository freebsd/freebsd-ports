# New ports collection makefile for:	mahogany
# Date created:		11 November 2000
# Whom:			Stephen Kiernan <sk-ports@vegamuse.org>
#
# $FreeBSD$
#

PORTNAME=		mahogany
PORTVERSION=		0.60
PORTREVISION=		1
CATEGORIES=		mail python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mahogany

MAINTAINER=		sk-ports@vegamuse.org

LIB_DEPENDS+=		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk
BUILD_DEPENDS+=		swig:${PORTSDIR}/devel/SWIG
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=		latex2html:${PORTSDIR}/textproc/latex2html
.endif

PYTHON_VERSION=		python1.5
USE_AUTOCONF_VER=	213
USE_GMAKE=		yes
CONFIGURE_ENV+=		OSTYPE=${OPSYS}

INSTALL_TARGET=		install_bin install_locale
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_doc
.endif

MAN1=			mahogany.1

CONFIGURE_ARGS=		--with-threads

post-install:
	@strip ${PREFIX}/bin/mahogany
	@cat pkg-message

.include <bsd.port.mk>
