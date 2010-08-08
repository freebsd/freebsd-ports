# New ports collection makefile for:	mod_vhs
# Date created:				Sun Jul 25 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_vhs
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.oav.net/openvisp/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	Mass virtual hosting using mod_ldap or mod_dbd with Apache 2.2.x

MANUAL_PACKAGE_BUILD=	needs apr with LDAP and DBD options enabled

USE_APACHE=	2.2+
USE_PHP=	yes
USE_PHP_BUILD=	yes
WANT_PHP_MOD=	yes
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	*.c

MAKE_JOBS_SAFE=	yes

AP_INC+=	${LOCALBASE}/include/home \
		   	-I ${LOCALBASE}/include/php \
			-I ${LOCALBASE}/include/php/Zend \
			-I ${LOCALBASE}/include/php/TSRM \
			-I ${LOCALBASE}/include/php/main
AP_EXTRAS+=	-DHAVE_MOD_PHP_SUPPORT

PORTDOCS=	ChangeLog AUTHORS README README.logs README.mod_suphp WARNING \
		README.phpopt THANKS WARNING WARNING.THREADS README.LDAP

OPTIONS=	LDAP	"Enable mod_ldap support"				on  \
		DBD	"Enable mod_dbd support"				off \
		ITK	"Enable mpm-itk support (needs a specific apache)"	off \
		VDEBUG	"Enable debug version (very verbose !)"			off

.include <bsd.port.options.mk>

### mod_vhs options
.if defined(WITH_LDAP)
.if defined(WITHOUT_DBD)
AP_EXTRAS+=	-DHAVE_LDAP_SUPPORT
.else
.error You cannot use LDAP and DBD at the same time.
.endif
.endif

.if defined(WITH_DBD)
.if defined(WITHOUT_LDAP)
AP_EXTRAS+=	-DHAVE_MOD_DBD_SUPPORT
.else
.error You cannot use LDAP and DBD at the same time.
.endif
.endif

.if defined(WITH_ITK)
AP_EXTRAS+=	-DHAVE_MPM_ITK_SUPPORT
.endif

.if defined(WITH_VDEBUG)
AP_EXTRAS+=	-DVH_DEBUG
.endif

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

# TODO :
#   Add suphp support

.include <bsd.port.mk>
