# New ports collection makefile for:	libieee1284
# Date created:		2004-12-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libieee1284
PORTVERSION=	0.2.10
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://cyberelk.net/tim/data/libieee1284/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IEEE1284 communications library

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
.endif

.include <bsd.port.pre.mk>

MAN3!=		${CAT} ${FILESDIR}/man3

.if defined(WITH_PYTHON)
CFLAGS+=	-I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${PYTHON_LIBDIR}
CONFIGURE_ARGS+=--with-python=yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--with-python=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README README.FreeBSD
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's,(objformat=).*,\1elf,' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
