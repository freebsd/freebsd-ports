# New ports collection makefile for:	Sary
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sary
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://prime.sourceforge.jp/freebsd/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A suffix array library and tools, which provide fast full-text search

CONFIGURE_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	glib20 gnomehack
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253
AUTOMAKE_ARGS=	-a
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

MAN1=		sary.1	mksary.1

pre-configure:
.if !defined(NOPORTDOCS)
	${FIND} ${WRKSRC}/docs -type f -name 'Makefile.am' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's,^docsdir = .*,docsdir = \$$(datadir)/doc/sary,'
.endif
	cd ${WRKSRC} && ${ACLOCAL}
	${REINPLACE_CMD} -e 's,--no-verify,,' ${WRKSRC}/aclocal.m4
	cd ${WRKSRC} && ${LIBTOOLIZE} && ${AUTOHEADER}

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs; ${MAKE} install
.endif

.include <bsd.port.mk>
