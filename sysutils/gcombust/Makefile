# New ports collection makefile for:	gcombust
# Date created:		Tue Jun 22 21:17:03 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	gcombust
PORTVERSION= 	0.1.28
CATEGORIES=	sysutils
MASTER_SITES=	http://www.abo.fi/~jmunsin/gcombust/

MAINTAINER=	nox@jelal.kn-bremen.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG=${PREFIX}/bin/gtk12-config

# for patch-ab (/dev/cd0a -> /dev/rcd0a)
post-configure:
	cd ${WRKSRC}/po && ${MAKE} update-po

post-install:
	${MKDIR} ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/gcombust

.include <bsd.port.mk>
