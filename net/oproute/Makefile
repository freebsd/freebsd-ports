# ex:ts=8
# New ports collection makefile for:	oproute
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oproute
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.opnix.com/oproute/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for measuring general performance of the Internet

PLIST_FILES=	bin/oproute
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
