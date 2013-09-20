# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		squirrelmail-translations
PORTVERSION=	1.4.18	# Translations updated less often than SM
CATEGORIES=		mail www
MASTER_SITES=	SF/squirrelmail/locales/${PORTVERSION}-${PORTDATE}
DISTNAME=		all_locales-${PORTVERSION}-${PORTDATE}
DIST_SUBDIR=	squirrelmail

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		NLS translations for Squirrelmail (mail/squirrelmail)

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

PORTDATE=		20090526

USE_BZIP2=		yes

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/${PORTNAME}
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB=		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

NO_STAGE=	yes
post-patch:
# The en_US help files are included with the main tarball
	@${RM} -r ${WRKSRC}/help/en_US

do-install:
	${MKDIR} ${SQUIRRELDIR}
.for DIR in help images locale
	cd ${WRKSRC} && ${FIND} ${DIR} | ${CPIO} -pdmu --quiet ${SQUIRRELDIR}
.endfor

.include <bsd.port.mk>
