# New ports collection makefile for:	spip
# Date created:				2006-03-17
# Whom:					jfb@minet.net
#
# $FreeBSD$
#

PORTNAME=	spip
PORTVERSION=	2.1.8
CATEGORIES=	www
MASTER_SITES=	http://files.spip.org/spip/archives/
DISTNAME=	SPIP-v${PORTVERSION:C|\.|-|1}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A publishing system for the Internet (CMS)

LICENSE=	GPLv3

BROKEN=		checksum is changing daily

USE_ZIP=	yes
USE_PHP=	mysql pcre zlib
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message

OPTIONS=	GD "With GD Support" on \
		IMAGICK "With ImageMagick Support" off \
		LDAP "With LDAP Support for authentification" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif

.if defined(WITH_IMAGICK)
USE_PHP+=	imagick
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name remove.txt | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -type f -name svn.revision | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -Rv ${WRKSRC}/* ${WWWDIR}
	@${CHGRP} -R ${WWWGRP} ${WWWDIR}
.for dir in config IMG ecrire local tmp
	@${CHMOD} 775 ${WWWDIR}/${dir}
.endfor
	@${MV} ${WWWDIR}/htaccess.txt ${WWWDIR}/.htaccess

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
