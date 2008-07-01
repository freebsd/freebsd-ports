# Ports collection makefile for:	misc/tinderbox
# Whom:			Edwin Groothuis <edwin@mavetju.org>
# Date created:		31 december 2005
#
# $FreeBSD$

PORTNAME=	tinderbox
#DISTVERSION=	${PORTVERSION}-${PORTREVISION}
PORTVERSION=	2.4.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
DIST_SUBDIR=	tinderbox

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Port build tinderbox system

OPTIONS=	PGSQL "With pgsql" Off \
		MYSQL "With mysql" On \
		CSUP  "Use csup for updates" On \
		CVSUP "Use cvsup for updates" Off \
		WEB   "Install web interface" Off \
		WEB_EXP "Install the new web interface" On \
		APACHE "Use Apache for web interface" On \
		LIGHTTPD "Use LightHTTPD for web interface" Off

NO_BUILD=	yes
WANT_PERL=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		tc-configCcache.1 tc-configDistfile.1 tc-configGet.1 \
		tc-configJail.1 tc-configTinderd.1 tc-init.1

.include <bsd.port.pre.mk>

.if !defined(WITH_PGSQL) && defined(WITHOUT_MYSQL)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose one of PGSQL and MYSQL
.endif

.if defined(WITH_WEB) || !defined(WITHOUT_WEB_EXP)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
WANT_PHP_WEB=	yes
USE_PHP=	session
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		favicon.ico tb242_template_paefchen_v2.tbz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.if defined(WITH_WEB)
PLIST_SUB+=	WEB=""
.else
PLIST_SUB+=	WEB="@comment "
.endif

.if !defined(WITHOUT_WEB_EXP)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-www-exp__core__TinderboxDS.php \
		${FILESDIR}/extra-patch-www-exp__module__moduleBuildPorts.php

PLIST_SUB+=	WEB_EXP=""
.else
PLIST_SUB+=	WEB_EXP="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.if defined(WITH_WEB) || !defined(WITHOUT_WEB_EXP)
USE_PHP+=	pgsql
.endif
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if !defined(WITHOUT_MYSQL)
.if defined(WITH_WEB) || !defined(WITHOUT_WEB_EXP)
USE_PHP+=	mysql
.endif
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323 40
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER:S/323//}
.endif

.if ! (${OSVERSION} > 700014 || ( ${OSVERSION} >= 601101 && ${OSVERSION} < 700000 ))
.if !defined(WITHOUT_CSUP)
RUN_DEPENDS+=	csup:${PORTSDIR}/net/csup
.endif
.endif

.if defined(WITH_CVSUP)
RUN_DEPENDS+=	cvsup:${PORTSDIR}/net/cvsup-without-gui
.endif

.if !defined(WITHOUT_APACHE) && (defined(WITH_WEB) || !defined(WITHOUT_WEB_EXP))
USE_APACHE=	1.3+
.elif defined(WITH_LIGHTTPD) && (defined(WITH_WEB) || !defined(WITHOUT_WEB_EXP))
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

pre-everything::
.if (!defined(WITHOUT_APACHE) || defined(WITH_LIGHTTPD)) && !(defined(WITH_WEB) || !defined(WITHOUT_WEB_EXP))
	@${ECHO_CMD} "It doesn't make sense to depend on Apache or LightHTTPD if not using either web interface."
	@${FALSE}
.endif

post-extract:
.if !defined(WITH_WEB)
	@${RM} -R ${WRKSRC}/www
.else
	@${CP} ${_DISTDIR}/favicon.ico ${WRKSRC}/www
.endif
.if defined(WITHOUT_WEB_EXP)
	@${RM} -R ${WRKSRC}/www-exp
.else
	@${CP} ${_DISTDIR}/favicon.ico ${WRKSRC}/www-exp
	@${TAR} -C ${WRKSRC}/www-exp/templates -xf ${_DISTDIR}/tb242_template_paefchen_v2.tbz
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/www-exp/templates/paefchen
	@${REINPLACE_CMD} 's|/templates/default|/templates/paefchen|' ${WRKSRC}/www-exp/inc_tinderbox.php.dist
	@${RM} ${WRKSRC}/www-exp/inc_tinderbox.php.dist.bak
.endif

post-patch:
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} \
		-e 's,DB_MAN_PREREQS=.*,DB_MAN_PREREQS="databases/p5-DBD-mysql${MYSQL_VER} databases/mysql${MYSQL_VER}-client",' \
		${WRKSRC}/lib/setup-mysql.sh
	@${RM} ${WRKSRC}/lib/setup-mysql.sh.bak
.endif
	@${RM} ${WRKSRC}/buildscript.orig
.if defined(WITH_WEB_EXP)
	@${RM} ${WRKSRC}/www-exp/core/TinderboxDS.php.orig
	@${RM} ${WRKSRC}/www-exp/module/moduleBuildPorts.php.orig
.endif

do-install:
	${MKDIR} ${PREFIX}/tinderbox/scripts
	${CP} -R ${WRKSRC}/* ${PREFIX}/tinderbox/scripts

post-install:
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
