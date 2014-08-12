# Created by: Vick Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	mod_authnz_crowd
PORTVERSION=	2.2.2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://downloads.atlassian.com/software/crowd/downloads/cwdapache/
DIST_SUBDIR=	apache2

MAINTAINER=	vivek@khera.org
COMMENT=	Apache 2.2.x module to use Atlassian Crowd for authentication

LICENSE=	APACHE20

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion \
		libcurl.so:${PORTSDIR}/ftp/curl

RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_dav_svn.so:${PORTSDIR}/www/mod_dav_svn

USES=		libtool
USE_AUTOTOOLS=	autoconf:env automake:env libtoolize
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_GCC=	any
USE_APACHE=	22
MAKE_JOBS_SAFE= yes

SUB_FILES=	pkg-message zzz_authnz_crowd.conf
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} \
		APACHEMODDIR=${APACHEMODDIR}

PLIST_FILES=	${APACHEMODDIR}/mod_authnz_crowd.so \
		${APACHEMODDIR}/mod_authz_svn_crowd.so \
		${APACHEETCDIR}/Includes/zzz_authnz_crowd.conf

LDFLAGS+=	-L${PREFIX}/lib

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/src/Makefile.am

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes


post-install:
	${INSTALL_DATA} ${WRKDIR}/zzz_authnz_crowd.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes/

.include <bsd.port.mk>
