# Created by: rasmus@kaj.se
# $FreeBSD$

PORTNAME=	gbuffy
PORTVERSION=	0.2.6
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/gbuffy/gbuffy-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ multiple mailbox "biff" program

LIB_DEPENDS=	libPropList.so:devel/libPropList \
		libcompface.so:mail/faces

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib
USE_GNOME=	gtk12
USE_OPENSSL=	yes

PLIST_FILES=	bin/gbuffy

post-patch:
	@${REINPLACE_CMD} -e 's|bindir)|DESTDIR)$$(&|' \
		-e 's|INSTALL)|BSD_INSTALL_PROGRAM)|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
