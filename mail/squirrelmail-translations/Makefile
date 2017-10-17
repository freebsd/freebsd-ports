# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squirrelmail-translations
PORTVERSION=	20170705
CATEGORIES=	mail www
MASTER_SITES=	http://snapshots.squirrelmail.org/ \
	http://freebsd.uzsolt.hu/src/
DISTNAME=	squirrelmail-${PORTVERSION}_0200-SVN.locales
DIST_SUBDIR=	squirrelmail

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	NLS translations for Squirrelmail (mail/squirrelmail)

LICENSE=	GPLv2

RUN_DEPENDS=	squirrelmail>=${PORTVERSION}:mail/squirrelmail

USES=		tar:bzip2 gettext
WRKSRC=		${WRKDIR}/squirrelmail.locales
NO_ARCH=	yes
PORTSCOUT=	ignore:1

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/squirrelmail
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB=	SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

do-build:
# The en_US help files are included with the main tarball
	@${RM} -r ${WRKSRC}/help/en_US

do-install:
	@${MKDIR} ${STAGEDIR}${SQUIRRELDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "help images locale" ${STAGEDIR}${SQUIRRELDIR})
	${FIND} ${STAGEDIR}${SQUIRRELDIR} -type d -empty -delete

.include <bsd.port.mk>
