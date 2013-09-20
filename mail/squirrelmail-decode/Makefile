# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		squirrelmail-decode
PORTVERSION=	1.2
CATEGORIES=		mail www
MASTER_SITES=	SF/squirrelmail/decode/${PORTVERSION}
DIST_SUBDIR=	squirrelmail

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Decoders to display extra character sets in SquirrelMail

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

USE_BZIP2=		yes
NO_BUILD=		yes

DOCSDIR=		${PREFIX}/share/doc/squirrelmail/decode
PORTDOCS=		*

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/${PORTNAME}
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB=		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

NO_STAGE=	yes
do-install:
	${MKDIR} ${SQUIRRELDIR}/functions/decode
.for DIR in eastasia x-mac
	cd ${WRKSRC}/${DIR} && ${FIND} . | ${CPIO} -pdmu --quiet ${SQUIRRELDIR}/functions/decode
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.decode ${DOCSDIR}
.endif

.include <bsd.port.mk>
