# New ports collection makefile for:	mod_dav (apache)
# Date created:		Sun Oct 17, 1999
# Whom:			patrick@mindstep.com
#
# $FreeBSD$
#

PORTNAME=	mod_dav
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/mod_dav/
DISTNAME=	mod_dav-${PORTVERSION}-${APACHE_VERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that provides DAV capabilities

# This port will work with the following version of Apache and anything newer.
APACHE_VERSION=	1.3.6

USE_APACHE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/apache \
		--mandir=${PREFIX}/man \
		--sysconfdir=${PREFIX}/etc/apache \
		--datadir=${PREFIX}/share/apache \
		--includedir=${PREFIX}/include/apache \
		--with-apxs=${APXS}

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		PATH="${PREFIX}/bin:${PREFIX}/sbin:${PATH}"

.if defined(WITH_SYMLINK_PATCH)
EXTRA_PATCHES=	${FILESDIR}/SYMLINK-mod_dav.h ${FILESDIR}/SYMLINK-dav_fs_repos.c
.endif

.if !defined(WITH_SYMLINK_PATCH)
pre-everything::
	@${ECHO_MSG} "Use WITH_SYMLINK_PATCH=yes to let mod_dav follow symlinks."
	@/bin/sleep 5
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/apache.conf.mod_dav ${PREFIX}/etc/apache
	@${ECHO_MSG} "*******************************************************"
	@${ECHO_MSG} "* Please review the mod_dav configuration in the main"
	@${ECHO_MSG} "* Apache configuration file."
	@${ECHO_MSG} "* ${PREFIX}/etc/apache/httpd.conf"
	@${ECHO_MSG} "*"
	@${ECHO_MSG} "* Look at the file ${PREFIX}/etc/apache/apache.conf.mod_dav"
	@${ECHO_MSG} "* for indications on what to do."
	@${ECHO_MSG} "*"
	@${ECHO_MSG} "*******************************************************"

.include <bsd.port.mk>
