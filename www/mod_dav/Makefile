# New ports collection makefile for:	mod_dav (apache)
# Date created:		Sun Oct 17, 1999
# Whom:			patrick@mindstep.com
#
# $FreeBSD$
#

PORTNAME=	mod_dav
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/mod_dav/
DISTNAME=	mod_dav-${PORTVERSION}-${APACHE_VERSION}

MAINTAINER=	patrick@mindstep.com

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

# This port will work with the following version of Apache and anything newer.
APACHE_VERSION=	1.3.6

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/apache \
		--mandir=${PREFIX}/man \
		--sysconfdir=${PREFIX}/etc/apache \
		--datadir=${PREFIX}/share/apache \
		--includedir=${PREFIX}/include/apache \
		--with-apxs=${PREFIX}/sbin/apxs

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		PATH="${PREFIX}/bin:${PREFIX}/sbin:${PATH}"

post-install:
	${INSTALL_DATA} ${FILESDIR}/apache.conf.mod_dav ${PREFIX}/etc/apache
	@${ECHO_MSG} "*******************************************************"
	@${ECHO_MSG} "* Please review the mod_dav configuration in the main"
	@${ECHO_MSG} "* Apache configuration file."
	@${ECHO_MSG} "* ${PREFIX}/etc/apache/apache.conf"
	@${ECHO_MSG} "*"
	@${ECHO_MSG} "* Look at the file ${PREFIX}/etc/apache/apache.conf.mod_dav"
	@${ECHO_MSG} "* for indications on what to do."
	@${ECHO_MSG} "*"
	@${ECHO_MSG} "*******************************************************"

.include <bsd.port.mk>
