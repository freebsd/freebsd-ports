# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	misc docs
PKGNAMEPREFIX=	zh_cn-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Simplified Chinese translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

DOCLANG=	zh_CN.UTF-8
DOCLANG_PREFIX=	zh_CN

.include "${MASTERDIR}/Makefile"

.if ${PORT_OPTIONS:MPDF}
BUILD_DEPENDS+=	${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf:chinese/arphicttf
.endif
