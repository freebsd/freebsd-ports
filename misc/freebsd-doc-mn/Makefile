CATEGORIES=	misc docs
PKGNAMEPREFIX=	mn-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Mongolian translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

# en-freebsd-doc installs the common files
HTML_RUN_DEPENDS=	en-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-en

DOCLANG=	mn

.include "${MASTERDIR}/Makefile"
