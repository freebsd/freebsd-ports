# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/security/gnome-gpg/Makefile,v 1.1 2006/09/02 15:20:58 ahze Exp $

PORTNAME=	gnome-gpg
PORTVERSION=	0.5.0
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple commandline wrapper around gpg for gnome-keyring

BUILD_DEPENDS=	gpgv:security/gnupg1
LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring
RUN_DEPENDS=	gpgv:security/gnupg1

USES=		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	libgnomeui
CONFIGURE_ENV=	set_more_warnings="no"
LIBS+=		-L${LOCALBASE}/lib -lX11

PLIST_FILES=	bin/gnome-gpg \
		man/man1/gnome-gpg.1.gz

.include <bsd.port.mk>
