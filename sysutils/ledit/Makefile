# ex:ts=8
# Ports collection makefile for:	ledit
# Date created:			Feb 8, 2005
# Whom:				Marwan Burelle <marwan.burelle@lri.fr>
#
# $FreeBSD$
#

PORTNAME=	ledit
PORTVERSION=	1.11
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/cristal/Daniel.de_Rauglaudre/Tools/

MAINTAINER=	marwan.burelle@lri.fr
COMMENT=	Line editor to be used with interactive commands

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

ALL_TARGET=	all ledit.opt

INSTALL_TARGET=	install.opt

PLIST_FILES=	bin/ledit

MANCOMPRESSED=	no

MANL=		ledit.l

.include <bsd.port.mk>
