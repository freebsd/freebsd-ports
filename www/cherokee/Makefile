# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
PORTVERSION=	0.4.17
CATEGORIES=	www
MASTER_SITES=	ftp://laurel.datsi.fi.upm.es/pub/linux/cherokee/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extremely fast and flexible web server

LIB_DEPENDS=	gnutls.12:${PORTSDIR}/security/gnutls

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

INSTALLS_SHLIB=	yes

MAN1=		cherokee-config.1 cherokee.1

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}

pre-install:
	@if [ ! -f ${PREFIX}/www ]; then \
		${MKDIR} ${PREFIX}/www;\
	fi
	@if [ ! -f ${PREFIX}/www/data ] ; then \
		${MKDIR} ${PREFIX}/www/data;\
	fi
	@${ECHO_MSG} " `pwd` "

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/Intro.txt ${DATADIR}
	@${ECHO_MSG} " "
	@${ECHO_MSG} " Dont forget to read the doc "
	@${ECHO_MSG} " ${PREFIX}/share/cherokee/Intro.txt"
	@${ECHO_MSG} " "

.include <bsd.port.mk>
