CATEGORIES=	misc docs
PKGNAMEPREFIX=	bn-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Bengali translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

# en-freebsd-doc installs the common files
HTML_RUN_DEPENDS=	en-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-en

DOCLANG=	bn-bd

.include "${MASTERDIR}/Makefile"
