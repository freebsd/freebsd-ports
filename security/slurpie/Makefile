# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	slurpie
PORTVERSION=	2.0b
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passwd file cracker (supports distributed nodes)

PLIST_FILES=	sbin/slurp sbin/slurpie
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e \
		's,(u_char)cfg.ptask_level = ,cfg.ptask_level = (u_int),' \
		${WRKSRC}/src/slurpie.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurp* ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
