# New ports collection makefile for:	gcombust
# Date created:		Tue Jun 22 21:17:03 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	gcombust
PORTVERSION=	0.1.33
CATEGORIES=	sysutils
MASTER_SITES=	http://www.abo.fi/~jmunsin/gcombust/

MAINTAINER=	nox@jelal.kn-bremen.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		cdlabelgen:${PORTSDIR}/print/cdlabelgen

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-included-gettext --datadir=${PREFIX}/share
CONFIGURE_ENV+=	GTK_CONFIG=${GTK_CONFIG} CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/include"

post-configure:
	cd ${WRKSRC}/po && ${MAKE} update-po

post-install:
	${MKDIR} ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/gcombust

.include <bsd.port.mk>
