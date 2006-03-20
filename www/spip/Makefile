# New ports collection makefile for:	spip
# Date created:				2006-03-17
# Whom:					jfb@minet.net
#
# $FreeBSD$
#

PORTNAME=	spip
PORTVERSION=	1.8.3
CATEGORIES=	www
MASTER_SITES=	http://www.spip.net/spip-dev/DISTRIB/ \
		http://trac.rezo.net/files/spip/
DISTNAME=	SPIP-v${PORTVERSION:U:C|\.|-|g}

MAINTAINER=	jfb@minet.net
COMMENT=	A publishing system for the Internet (CMS)

USE_ZIP=	yes
USE_PHP=	mysql pcre
NO_BUILD=	yes

WWWDOCROOT?=	www
SPIPDIR?=	${WWWDOCROOT}/${PORTNAME:L}

SUB_FILES=	pkg-message
SUB_LIST=	SPIPDIR=${SPIPDIR}
PLIST_SUB=	SPIPDIR=${SPIPDIR}

OPTIONS=	GD "With GD Support" on \
		IMAGICK     "With ImageMagick Support" off \
		LDAP "With LDAP Support for authentification" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/gd.so:${PORTSDIR}/${gd_DEPENDS}
.endif

.if defined(WITH_IMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/${imagick_DEPENDS}
.endif

.if defined(WITH_LDAP)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/ldap.so:${PORTSDIR}/${ldap_DEPENDS}
.endif

do-install:
	@${MKDIR} ${PREFIX}/${SPIPDIR}
	@${CP} -Rv ${WRKSRC}/* ${PREFIX}/${SPIPDIR}
	@${CHGRP} -R ${WWWGRP} ${PREFIX}/${SPIPDIR}
.for dir in CACHE IMG ecrire ecrire/data
	@${CHMOD} 775 ${PREFIX}/${SPIPDIR}/${dir}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
