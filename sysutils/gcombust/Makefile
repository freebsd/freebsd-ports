# New ports collection makefile for:	gcombust
# Date created:		Tue Jun 22 21:17:03 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	gcombust
PORTVERSION=	0.1.53
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.abo.fi/~jmunsin/gcombust/

MAINTAINER=	mcdouga9@msu.edu
COMMENT=	A GTK+ frontend for mkisofs and cdrecord

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		cdlabelgen:${PORTSDIR}/print/cdlabelgen

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk12 gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-included-gettext --datadir=${PREFIX}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|==|=|g' ${WRKSRC}/po/Makefile.in.in

post-configure:
	cd ${WRKSRC}/po && ${MAKE} update-po

post-install:
	@${MKDIR} ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/gcombust

.include <bsd.port.mk>
