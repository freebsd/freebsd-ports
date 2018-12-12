# $FreeBSD$

PORTNAME=	intervaltree
DISTVERSION=	g20151213
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Minimal C++ interval tree implementation

LICENSE=	MIT

USES=		compiler:c++0x
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	8fc4be91866237995e1105689d84bece619f4663

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/interval_tree_test include/${PORTNAME}/IntervalTree.h

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
post-patch:
	${REINPLACE_CMD} -e 's|<bool, unsigned long>|<bool, unsigned int>|g' \
		${WRKSRC}/interval_tree_test.cpp
.endif

.include <bsd.port.post.mk>
