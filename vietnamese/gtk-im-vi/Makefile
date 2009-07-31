# New ports collection makefile for:  gtk-im-vi
# Date created:                   2006/01/08
# Whom:                           chinsan
#
# $FreeBSD$
#

PORTNAME=	gtk-im-vi
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	vietnamese textproc gnome
MASTER_SITES=	http://dev.gentoo.org/~pclouds/files/

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Simple GTK+ input methods for Vietnamese(VNI and TELEX)

GNU_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_LDCONFIG=	YES

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},; s,ChangeLog,,' \
		${WRKSRC}/Makefile.in ${WRKSRC}/po/Makefile.in.in

post-install:
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.post.mk>
