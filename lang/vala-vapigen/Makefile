# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/lang/vala-vapigen/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTREVISION=	1
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-vapigen

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vapigen program from vala

MASTERDIR=	${.CURDIR}/../vala
BUILD_WRKSRC=	${WRKSRC}/vapigen
INSTALL_WRKSRC=	${WRKSRC}/vapigen
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

VALA_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
