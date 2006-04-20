# New ports collection makefile for:	gtk-knocker
# Date created:				Tue Jul 10 02:18:39 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	knocker
PORTVERSION=	0.6.6
PORTREVISION=	2
CATEGORIES=	security net x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gtk-
DISTNAME=	gtk-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and easy to use TCP only port scanner (GTK+ version)

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes
USE_GNOME=	gtk12

MAN1=		gtk-knocker.1

.include <bsd.port.pre.mk>

post-patch:
.for file in src/gtk_support.c src/gtk_callbacks.c
	@${REINPLACE_CMD} -e 's|"\.\./pixmaps"|PACKAGE_DATA_DIR "/pixmaps"|g' \
		${WRKSRC}/${file}
.endfor
.for file in src/license.h
	@${REINPLACE_CMD} -e 's|$$|\\n\\|g ; \
		 s|^".*|";|g' ${WRKSRC}/${file}
.endfor

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/gtk-knocker.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
