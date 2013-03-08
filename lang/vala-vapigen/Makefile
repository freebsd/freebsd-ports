# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/lang/vala-vapigen/Makefile,v 1.7 2012/12/17 19:46:24 kwm Exp $

PORTREVISION=	0
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-vapigen

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The vapigen program from vala

MASTERDIR=	${.CURDIR}/../vala
BUILD_WRKSRC=	${WRKSRC}/vapigen
INSTALL_WRKSRC=	${WRKSRC}/vapigen
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

VALA_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
