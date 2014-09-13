# Created by: rasmus@kaj.se
# $FreeBSD$

PORTNAME=	gbuffy
PORTVERSION=	0.2.6
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/gbuffy/gbuffy-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ multiple mailbox "biff" program

LIB_DEPENDS=	libPropList.so:${PORTSDIR}/devel/libPropList \
		libcompface.so:${PORTSDIR}/mail/faces

PLIST_FILES=	bin/gbuffy
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|bindir)|DESTDIR)$$(&|' \
		-e 's|INSTALL)|BSD_INSTALL_PROGRAM)|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
