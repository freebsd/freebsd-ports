# New ports collection makefile for:		lighttpd
# Date created:					20 May 2004
# Whom:						k@123.org
#
# $FreeBSD$
#

PORTNAME=	lighttpd
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://jan.kneschke.de/projects/lighttpd/download/ \
				http://dl.fkb.wormulon.net/lighttpd/ \
				http://dl.kel.wormulon.net/lighttpd/

MAINTAINER=	hendrik@scholz.net
COMMENT=	A secure, fast, compliant, and very flexible Web Server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOCONF_VER=	259
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
USE_LIBTOOL_VER=	15
USE_GNOME=	lthack
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include LIBS=-L${PREFIX}/lib
STARTUP_FILE=	${PREFIX}/etc/rc.d/lighttpd.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl
.endif

MAN1=		lighttpd.1

pre-everything::
.if !defined(WITHOUT_OPENSSL)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable SSL support by defining WITHOUT_OPENSSL"
.endif

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/lighttpd.sh.tmpl > ${STARTUP_FILE}
	@${CHMOD} 755 ${STARTUP_FILE}
	@${INSTALL_DATA} ${FILESDIR}/lighttpd.conf.sample ${PREFIX}/etc/
	@${LIBTOOL} --finish ${PREFIX}/lib

.include <bsd.port.mk>
