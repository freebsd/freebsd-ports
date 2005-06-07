# New ports collection makefile for:    txt2pdbdoc
# Date created:         Mon Jan 8 2001
# Whom:                 keichii@iteration.net
#
# $FreeBSD$
#

PORTNAME=	txt2pdbdoc
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	palm converters
MASTER_SITES=	http://tirian.magd.ox.ac.uk/~dom/palm/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts plain text and HTML files to Palm Pilot Doc formats

USE_GMAKE=	yes
MAKE_ARGS=	MAKE=gmake CC=${CC} CFLAGS="${CFLAGS}" I_ROOT=${PREFIX}

PLIST_FILES=	bin/pdbtxt2html bin/html2pdbtxt bin/txt2pdbdoc
MAN1=		txt2pdbdoc.1 pdbtxt2html.1 html2pdbtxt.1
MAN4=		pdb.4 doc.4

.include <bsd.port.mk>
