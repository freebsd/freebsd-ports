# New ports collection makefile for:	mod_dav (apache)
# Date created:		Sun Oct 17, 1999
# Whom:			patrick@mindstep.com
#
# $FreeBSD$
#

PORTNAME=	mod_dav
PORTVERSION=	1.0.3
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.3.6

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that provides DAV capabilities

MAKE_JOBS_SAFE=  yes

OPTIONS=	SYMLINK_PATCH	"Follow Symlinks" off \
			APACHE_EXPAT	"Use Bundled expat library" on

PKGDEINSTALL=	${PKGINSTALL}

SUB_FILES+=	pkg-install pkg-message
SUB_LIST+=	APXS=${APXS} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PLIST_FILES=	${APACHEETCDIR}/apache.conf.mod_dav ${APACHEMODDIR}/libdav.so

USE_APACHE=	1.3
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--bindir=${LOCALBASE}/bin \
		--sbindir=${LOCALBASE}/sbin \
		--libexecdir=${LOCALBASE}/${APACHEMODDIR} \
		--sysconfdir=${LOCALBASE}/${APACHEETCDIR} \
		--datadir=${LOCALBASE}/share/apache \
		--includedir=${LOCALBASE}/${APACHEINCLUDEDIR} \
		--with-apxs=${APXS}

.include <bsd.port.pre.mk>
.if defined(WITHOUT_APACHE_EXPAT)
CONFIGURE_ARGS+=	--with-expat=${LOCALBASE}
LIB_DEPENDS+=		expat.6:${PORTSDIR}/textproc/expat2
.endif

.if defined(WITH_SYMLINK_PATCH)
EXTRA_PATCHES=	${FILESDIR}/SYMLINK-${PORTNAME}.h ${FILESDIR}/SYMLINK-dav_fs_repos.c
.endif

do-install:
	BINMODE=755 ${INSTALL_PROGRAM} ${WRKSRC}/libdav.so ${LOCALBASE}/${APACHEMODDIR}/
	${INSTALL_DATA} ${FILESDIR}/apache.conf.${PORTNAME} ${LOCALBASE}/${APACHEETCDIR}/

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
