# New ports collection makefile for:   sahana-phase2
# Date created:        29 March 2006
# Whom:                Janaka Wickramasinghe <janaka@opensource.lk>
#
# $FreeBSD$
#

PORTNAME=	sahana2
DISTVERSION=	0.2.0-beta-1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sahana

MAINTAINER=	janaka@opensource.lk
COMMENT=	Sahana is a web based disaster management system

RUN_DEPENDS=	${LOCALBASE}/share/adodb:${PORTSDIR}/databases/adodb \
		${LOCALBASE}/lib/php/creole:${PORTSDIR}/databases/php5-creole \
		${PEARDIR}/simpletest:${PORTSDIR}/devel/simpletest

BROKEN=		Conflicting dependencies: php4 vs php5
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

NO_BUILD=	yes
USE_PHP=	gd gettext
WRKSRC=		${WRKDIR}/sahana-phase2

WANT_PHP_WEB=	yes

OPTIONS=	DB_MYSQL "Enable MySQL" on \
		DB_POSTGRES "Enable PostgreSQL" off \
		DB_SQLITE "Enable SQLite" off

SAHANADIR=	www/sahana-phase2
PLIST_SUB=	SAHANADIR=${SAHANADIR}

SUB_FILES=	pkg-message
SUB_LIST=	SAHANADIR="${SAHANADIR}"

.include <bsd.port.pre.mk>

PHP_CONFIG?=	${LOCALBASE}/bin/php-config

.if !defined(PEARDIR) && exists(${PHP_CONFIG})
_PEARPREFIX!=	${PHP_CONFIG} --prefix
_PEARDIR=	share/pear
PEARDIR=	${_PEARPREFIX}/${_PEARDIR}
.endif

.if defined(WITH_DB_MYSQL)
    USE_PHP+=	mysql
.endif

.if defined(WITH_DB_POSTGRES)
    USE_PHP+=	pgsql
.endif

.if defined(WITH_DB_SQLITE)
    USE_PHP+=	sqlite
.endif

post-extract:
	@cd ${WRKSRC}/3rd && ${RM} -r adodb creole simpletest

do-install:
	cd ${WRKSRC} && \
	for src in $$( ${FIND} .) ; do \
		dst=${PREFIX}/${SAHANADIR}$${src#.} ; \
		if ${TEST} -d "$$src" ; then \
			${MKDIR} "$$dst" ; \
		else \
			${INSTALL_DATA} "$$src" "$$dst" ; \
		fi \
	done
	@${LN} -s ${LOCALBASE}/share/adodb ${LOCALBASE}/lib/php/creole \
		${PEARDIR}/simpletest ${PREFIX}/${SAHANADIR}/3rd

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
