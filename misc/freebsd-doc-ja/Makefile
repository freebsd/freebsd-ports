# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	misc docs
PKGNAMEPREFIX=	ja-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Japanese translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

DOCLANG=	ja_JP.eucJP

.include "${MASTERDIR}/Makefile"

.if ${PORT_OPTIONS:MPDF} || ${PORT_OPTIONS:MPS}
BUILD_DEPENDS+=	${LOCALBASE}/share/fonts/ipa/ipam.otf:japanese/font-ipa
.endif
