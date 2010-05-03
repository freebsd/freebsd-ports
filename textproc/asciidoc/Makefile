# New ports collection makefile for:   asciidoc
# Date created:        9 Feb 2006
# Whom:                anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	asciidoc
PORTVERSION=	8.5.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.methods.co.nz/asciidoc/ \
		SF

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	A text document format for writing short documents and man pages

USE_PYTHON=	2.4+
USE_GMAKE=	yes
MAKE_ENV=	INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" INSTALL_DATA="${INSTALL_DATA}"

GNU_CONFIGURE=	yes
MAN1=		a2x.1 asciidoc.1

# a future improvement to this port is to also install the vim syntax
# highlighing mode which is currently disabled by being patched away in
# Makefile.in

.include <bsd.port.mk>
