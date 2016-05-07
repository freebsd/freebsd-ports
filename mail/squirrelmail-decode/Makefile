# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squirrelmail-decode
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	SF/squirrelmail/decode/${PORTVERSION}
DIST_SUBDIR=	squirrelmail

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Decoders to display extra character sets in SquirrelMail

LICENSE=	GPLv2

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:mail/squirrelmail

USES=		tar:bzip2
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/squirrelmail/decode

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/squirrelmail
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB=	SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${SQUIRRELDIR}/functions/decode
.for DIR in eastasia x-mac
	${INSTALL_DATA} ${WRKSRC}/${DIR}/*.php ${STAGEDIR}${SQUIRRELDIR}/functions/decode
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.decode ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
