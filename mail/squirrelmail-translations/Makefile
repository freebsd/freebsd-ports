# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		squirrelmail-translations
PORTVERSION=	20140420
CATEGORIES=		mail www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw/squirrelmail
DISTNAME=		squirrelmail-${PORTVERSION}_0200-SVN.locales
DIST_SUBDIR=	squirrelmail

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		NLS translations for Squirrelmail (mail/squirrelmail)

LICENSE=		GPLv2

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

USES=			tar:bzip2 gettext

WRKSRC=			${WRKDIR}/squirrelmail.locales

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/squirrelmail
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB=		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

do-build:
# The en_US help files are included with the main tarball
	@${RM} -r ${WRKSRC}/help/en_US

do-install:
	@${MKDIR} ${STAGEDIR}${SQUIRRELDIR}
.for DIR in help images locale
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${SQUIRRELDIR})
.endfor

.include <bsd.port.mk>
