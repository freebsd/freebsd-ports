# ex:ts=8
# Ports collection makefile for:	ledit
# Date created:			Feb 8, 2005
# Whom:				Marwan Burelle <marwan.burelle@lri.fr>
#
# $FreeBSD$
#

PORTNAME=	ledit
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/cristal/Daniel.de_Rauglaudre/Tools/ \
		http://home.leo.org/~barner/freebsd/distfiles/

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Line editor to be used with interactive commands

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

ALL_TARGET=	all ledit.opt

PLIST_FILES=	bin/ledit

MAN1=		ledit.1

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ledit.out ${PREFIX}/bin/ledit
	${INSTALL_MAN} ${WRKSRC}/ledit.l ${MANPREFIX}/man/man1/ledit.1

.include <bsd.port.post.mk>
