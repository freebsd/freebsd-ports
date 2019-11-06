# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	mod_vhs
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.oav.net/openvisp/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	Mass virtual hosting using mod_ldap or mod_dbd with Apache 2.2.x

BROKEN=		unfetchable

LICENSE=	APACHE11

MANUAL_PACKAGE_BUILD=	needs apr with LDAP and DBD options enabled

USES=		apache:2.2+ php:mod,build cpe
CPE_VENDOR=	xavier_beaudouin
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	*.c

AP_INC+=	${LOCALBASE}/include/home \
			-I ${LOCALBASE}/include/php \
			-I ${LOCALBASE}/include/php/Zend \
			-I ${LOCALBASE}/include/php/TSRM \
			-I ${LOCALBASE}/include/php/main
AP_EXTRAS+=	-DHAVE_MOD_PHP_SUPPORT

PORTDOCS=	ChangeLog AUTHORS README README.logs README.mod_suphp \
		README.phpopt THANKS WARNING WARNING.THREADS README.LDAP

OPTIONS_DEFINE=	LDAP DBD ITK VDEBUG DOCS
OPTIONS_DEFAULT=	LDAP
LDAP_DESC=	mod_ldap support
DBD_DESC=	mod_dbd support
ITK_DESC=	mpm-itk support (needs a specific apache)
VDEBUG_DESC=	debug version (very verbose !)

.include <bsd.port.options.mk>

### mod_vhs options
.if ${PORT_OPTIONS:MLDAP}
.if ! ${PORT_OPTIONS:MDBD}
AP_EXTRAS+=	-DHAVE_LDAP_SUPPORT
.else
.error You cannot use LDAP and DBD at the same time.
.endif
.endif

.if ${PORT_OPTIONS:MDBD}
.if ! ${PORT_OPTIONS:MLDAP}
AP_EXTRAS+=	-DHAVE_MOD_DBD_SUPPORT
.else
.error You cannot use LDAP and DBD at the same time.
.endif
.endif

.if ${PORT_OPTIONS:MITK}
AP_EXTRAS+=	-DHAVE_MPM_ITK_SUPPORT
.endif

.if ${PORT_OPTIONS:MVDEBUG}
AP_EXTRAS+=	-DVH_DEBUG
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

# TODO :
#   Add suphp support

.include <bsd.port.mk>
