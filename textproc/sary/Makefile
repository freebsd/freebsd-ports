# New ports collection makefile for:	Sary
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sary
PORTVERSION=	1.0.4
CATEGORIES=	textproc
MASTER_SITES=	http://sary.namazu.org/stable/

MAINTAINER=	knu@FreeBSD.org

USE_GNOMENG=	yes
USE_GNOME=	glib12 gnomehack
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN1=		sary.1	mksary.1

post-patch:
	${REINPLACE_CMD} -e 's,glib-config,${GLIB_CONFIG},g' \
		${WRKSRC}/configure ${WRKSRC}/sary-config.in
.if !defined(NOPORTDOCS)
	${FIND} ${WRKSRC}/docs -type f -name 'Makefile.in' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's,^docsdir = .*,docsdir = \$$(datadir)/doc/sary,'
.endif

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs; ${MAKE} install
.endif

.include <bsd.port.mk>
