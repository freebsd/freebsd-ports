# New ports collection makefile for:	asp2php
# Date created:				Thu 29 Jun 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	asp2php
PORTVERSION=	0.76.10
CATEGORIES=	www
MASTER_SITES=	http://65.108.58.129/asp2php/

MAINTAINER=	erwin@lansing.dk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}/src

WANT_GTK=	yes
MAKE_ENV=	FLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
ALL_TARGET=	default gui
PLIST_SUB+=	WANT_GTK=""
.else
ALL_TARGET=	default
PLIST_SUB+=	WANT_GTK="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${PERL} -pi -e \
		's|^CC=|#CC=|g ; \
		 s| make| \$$\{MAKE\}|g ; \
		 s|`gtk-config|`\$$\{GTK_CONFIG\}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asp2php ${PREFIX}/bin
.if defined(HAVE_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/gtkasp2php ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
