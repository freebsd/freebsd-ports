# New ports collection makefile for:   	LDAP-Account-Manager
# Date created:				August, 2nd 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	LDAP-Account-Manager
PORTVERSION=	0.3
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lam
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

RUN_DEPENDS=	${LOCALBASE}/${MOD_DIR}/libphp4.so:${PORTSDIR}/www/apache2 \
		${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota\
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

USE_REINPLACE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/lam

.if defined(WITH_APACHE2)
MOD_DIR=	libexec/apache2
.else
MOD_DIR=	libexec/apache
.endif

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/lib/libldap.so.2)
IGNORE+=	"OpenLDAP support is required \(2.0 or greater\)"
.endif

.if !exists(${LOCALBASE}/lib/libmcrypt.so)
IGNORE+=	"mcrypt support is required"
.endif

.if !exists(${LOCALBASE}/lib/libintl.so)
IGNORE+=	"gettext support is required"
.endif

WWW_ROOT?=	www/lam
PLIST_SUB+=	WWWROOT=${WWW_ROOT}
WWW_USER?=	www
WWW_GROUP?=	www
WWW_DIR=	config graphics help lib locale sess style templates
DOC_FILES=	COPYING HISTORY INSTALL README TODO docs/README.fpdf \
		docs/README.lamdaemon.pl docs/README.openldap docs/README.shells

CVS_DIRS=	${WRKSRC}/lib/font/CVS ${WRKSRC}/lib/font/makefont/CVS

post-extract:
	@${RM} -fr ${CVS_DIRS}

do-install:
	@${MKDIR} ${PREFIX}/${WWW_ROOT}
	@${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/${WWW_ROOT}
.for DIR in ${WWW_DIR}
	@${MKDIR} ${PREFIX}/${WWW_ROOT}/${DIR}
	@${CP} -Rf ${WRKSRC}/${DIR} ${PREFIX}/${WWW_ROOT}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${CHOWN} -R ${WWW_USER}:${WWW_GROUP} ${PREFIX}/${WWW_ROOT}

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  To use LDAP-account-manager, you have to install"
	@${ECHO_MSG} "  and set up Samba 2.x or 3.x schemas."
	@${ECHO_MSG} "  Like this :"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/core.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/cosine.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/inetorgperson.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/nis.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/samba.schema"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
