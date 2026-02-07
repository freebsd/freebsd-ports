CATEGORIES=	misc docs
PKGNAMEPREFIX=	zh_tw-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Traditional Chinese translation of the FreeBSD Documentation Project

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

# en-freebsd-doc installs the common files
HTML_RUN_DEPENDS=	en-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-en

DOCLANG=	zh-tw

.include "${MASTERDIR}/Makefile"
