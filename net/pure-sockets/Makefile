# New ports collection makefile for:	pure-sockets
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-sockets
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to the Berkeley socket functions

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900014
BUILD_DEPENDS+=	clang>=2.8:${PORTSDIR}/lang/clang
.endif
LIB_DEPENDS+=	pure.7:${PORTSDIR}/lang/pure

LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	lib/pure/sockets.pure \
		lib/pure/sockets.so

USE_GMAKE=	yes

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}"

PORTEXAMPLES=	*

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
