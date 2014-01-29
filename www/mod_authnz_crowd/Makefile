# Created by: Vick Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	mod_authnz_crowd
PORTVERSION=	2.2.2
CATEGORIES=	www
MASTER_SITES=	http://downloads.atlassian.com/software/crowd/downloads/cwdapache/
DIST_SUBDIR=	apache2

MAINTAINER=	vivek@khera.org
COMMENT=	Apache 2.2.x module to use Atlassian Crowd for authentication

LICENSE=	APACHE20

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion \
		libcurl.so:${PORTSDIR}/ftp/curl

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_GCC=	any
USE_APACHE=	22
MAKE_JOBS_SAFE= yes

MANUAL_PACKAGE_BUILD=	requires subversion build with MOD_DAV_SVN.

SUB_FILES=	pkg-message zzz_authnz_crowd.conf
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} \
		APACHEMODDIR=${APACHEMODDIR}

PLIST_FILES=	${APACHEMODDIR}/mod_authnz_crowd.so \
		${APACHEMODDIR}/mod_authz_svn_crowd.so \
		${APACHEETCDIR}/Includes/zzz_authnz_crowd.conf

LDFLAGS+=	-L${PREFIX}/lib

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKDIR}/zzz_authnz_crowd.conf \
		${PREFIX}/${APACHEETCDIR}/Includes/
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
