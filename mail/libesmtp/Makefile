# New ports collection makefile for:    libesmtp
# Date created:         Sun Feb 21 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	0.8.7
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/

MAINTAINER=	jmcoopr@webmail.bmi.net

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	${WRKSRC}/aclocal.m4 ${WRKSRC}/libltdl/aclocal.m4
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

# require-all-recipients (implied by enable-all) is required for Balsa-1.2.x
CONFIGURE_ARGS=	--enable-all \
		--disable-ltdl-install

pre-build:
	@${CP} ${WRKSRC}/libltdl/libtool ${WRKSRC}/libtool

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/libesmtp
	${MKDIR} ${PREFIX}/share/doc/libesmtp
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/libesmtp
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/libesmtp
	${INSTALL_DATA} ${WRKSRC}/Notes ${PREFIX}/share/doc/libesmtp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libesmtp
.endif

.include <bsd.port.mk>
