# New ports collection makefile for:   w3m
# Version required:		990928
# Date Created:			7 Oct 1999
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

DISTNAME=	w3m-990928
CATEGORIES?=	www
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/w3m/ \
		ftp://ftp.firedrake.org/w3m/

MAINTAINER=	nobutaka@nobutaka.com

WRKSRC=		${WRKDIR}/w3m
TARGET=		${WRKSRC}/config.h

.if !defined(JAPANESE_MSG)
pre-extract:
	@${ECHO} "Try ports/japanese/w3m if you prefer Japanese messages."
.endif

post-configure:
	@${CP} ${TARGET} ${TARGET}.in
.if defined(JAPANESE_MSG)
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,#undef JAPANESE_MSG,#define JAPANESE_MSG,g" \
		-e "s,w3mhelp_en.html,w3mhelp_ja.html,g" \
	< ${TARGET}.in > ${TARGET}
.else
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	< ${TARGET}.in > ${TARGET}
.endif

.include <bsd.port.mk>
