# New ports collection makefile for:	f-prot-sig
# Date created:				11 Feb 2004
# Whom:                                 Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	f-prot-sig
PORTVERSION=	20040302
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.f-prot.com/pub/

DISTFILES=	fp-def.zip \
		macrdef2.zip

MAINTAINER=	tim@bishnet.net
COMMENT=	F-Prot Antivirus Signatures

# F-Prot does not version their .DEF files so the port always pulls the latest.
NO_CHECKSUM=	yes

NO_PACKAGE=	Free for personal use only
NO_CDROM=	Free for personal use only
RESTRICTED=	Free for personal use only

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
USE_ZIP=	YES

post-extract:
.for fetched in ${DISTFILES}
	${MV} ${DISTDIR}/${fetched} ${DISTDIR}/${fetched}-${PORTVERSION}.zip
.endfor

do-install:
	${MKDIR} ${PREFIX}/f-prot
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/f-prot

	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"

.include <bsd.port.mk>
