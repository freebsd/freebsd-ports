# ex:ts=8
# Ports collection makefile for:  slurpie
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	slurpie
PORTVERSION=	2.0b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A passwd file cracker (supports distributed nodes)

PLIST_FILES=	sbin/slurp sbin/slurpie
PORTDOCS=	README

post-patch:
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e \
		's,(u_char)cfg.ptask_level = ,cfg.ptask_level = (u_int),' \
		${WRKSRC}/src/slurpie.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurp* ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
