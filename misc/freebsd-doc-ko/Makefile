# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	misc docs
PKGNAMEPREFIX=	ko-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Korean translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

DOCLANG=	ko_KR.UTF-8

.include "${MASTERDIR}/Makefile"

.if ${PORT_OPTIONS:MPDF}
BUILD_DEPENDS+=	${LOCALBASE}/share/fonts/nanum-ttf/NanumBarunGothic.ttf:korean/nanumfonts-ttf
.endif
