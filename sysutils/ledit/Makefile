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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Line editor to be used with interactive commands

DEPRECATED=	${BROKEN}
EXPIRATION_DATE=        2006-07-14

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

BROKEN=		Does not build

ALL_TARGET=	all ledit.opt

INSTALL_TARGET=	install.opt

PLIST_FILES=	bin/ledit

MANCOMPRESSED=	no

MANL=		ledit.l

.include <bsd.port.mk>
