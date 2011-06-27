# New ports collection makefile for:	pure-xml
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-xml
PORTVERSION=	0.6
CATEGORIES=	textproc
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface for libxml2 and libxslt

LIB_DEPENDS=	pure.7:${PORTSDIR}/lang/pure

LICENSE_FILE=	${WRKSRC}/COPYING

USE_GCC=	4.2+
USE_GMAKE=	yes
USE_GNOME=	libxml2 libxslt

PLIST_FILES=	lib/pure/xml.pure \
		lib/pure/xml.so

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}"

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
