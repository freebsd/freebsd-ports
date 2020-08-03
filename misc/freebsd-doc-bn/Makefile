# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	misc docs
PKGNAMEPREFIX=	bn-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Bengali translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

DOCLANG=	bn_BD.UTF-8

.include "${MASTERDIR}/Makefile"

.if ${PORT_OPTIONS:MPDF}
BUILD_DEPENDS+=	${LOCALBASE}/share/fonts/Lohit/Lohit-Bengali.ttf:x11-fonts/lohit
.endif
