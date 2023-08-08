CATEGORIES=	misc docs
PKGNAMEPREFIX=	hu-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Hungarian translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

# en-freebsd-doc installs the common files
HTML_RUN_DEPENDS=	en-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-en

DOCLANG=	hu

.include "${MASTERDIR}/Makefile"
