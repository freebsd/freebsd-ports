# Created by: Vick Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	mod_authnz_crowd
PORTVERSION=	2.2.2
PORTREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://downloads.atlassian.com/software/crowd/downloads/cwdapache/
DIST_SUBDIR=	apache2

MAINTAINER=	vivek@khera.org
COMMENT=	Apache 2.2+ module to use Atlassian Crowd for authentication

LICENSE=	APACHE20

BROKEN_mips=		fails to build: error: curl/curl.h: No such file or directory
BROKEN_mips64=		fails to build: error: curl/curl.h: No such file or directory
BROKEN_powerpc64=	fails to build: error: curl/curl.h: No such file or directory

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_dav_svn.so:www/mod_dav_svn

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib
USES=		apache:2.2+ autoreconf libtool
USE_GNOME=	libxml2
USE_GCC=	any

SUB_FILES=	pkg-message zzz_authnz_crowd.conf
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} \
		APACHEMODDIR=${APACHEMODDIR} \
		AP_MODULE=mod_authnz_crowd

PLIST_FILES=	${APACHEMODDIR}/mod_authnz_crowd.so \
		${APACHEMODDIR}/mod_authnz_crowd.so.0.0.0 \
		${APACHEMODDIR}/mod_authz_svn_crowd.so \
		${APACHEMODDIR}/mod_authz_svn_crowd.so.0.0.0 \
		${APACHEETCDIR}/Includes/zzz_authnz_crowd.conf

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/src/Makefile.am
	${REINPLACE_CMD} -e 's|%%APACHEETCDIR%%|${APACHEETCDIR}|g' \
		-e 's|%%APACHEINCLUDEDIR%%|${APACHEINCLUDEDIR}|g' \
		-e 's|%%APACHEMODDIR%%|${APACHEMODDIR}|g' \
		${WRKSRC}/configure.ac

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes

post-install:
	${INSTALL_DATA} ${WRKDIR}/zzz_authnz_crowd.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes/

.include <bsd.port.mk>
