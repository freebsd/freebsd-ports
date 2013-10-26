# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=		squirrelmail-decode
PORTVERSION=	1.2
CATEGORIES=		mail www
MASTER_SITES=	SF/squirrelmail/decode/${PORTVERSION}
DIST_SUBDIR=	squirrelmail

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Decoders to display extra character sets in SquirrelMail

LICENSE=		GPLv2

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

USE_BZIP2=		yes
NO_BUILD=		yes

DOCSDIR=		${PREFIX}/share/doc/squirrelmail/decode

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/squirrelmail
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB=		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

do-install:
	${MKDIR} ${STAGEDIR}${SQUIRRELDIR}/functions/decode
.for DIR in eastasia x-mac
	cd ${WRKSRC}/${DIR} && ${FIND} . | ${CPIO} -pdmu --quiet ${STAGEDIR}${SQUIRRELDIR}/functions/decode
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.decode ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
