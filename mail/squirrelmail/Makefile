# New ports collection makefile for:	squirrelmail
# Date created: 			27 December 2001
# Whom: 				Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail
PORTVERSION=	1.2.9
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	squirrelmail

MAINTAINER=	simond@irrelevant.org

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

USE_BZIP2=	yes
NO_BUILD=	yes

pre-install:
	@${ECHO} "Your umask should be lax while installing this. Like, 022 or something."
	@${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${PREFIX}/squirrelmail
	${CP} -R ${WRKSRC}/* ${PREFIX}/squirrelmail
	${CHOWN} -R www:www ${PREFIX}/squirrelmail/data

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
