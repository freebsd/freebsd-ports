# New ports collection makefile for:	ggsd
# Date created:				14 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	ggsd
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	billf
DISTNAME=	ggsd
EXTRACT_SUFX=	.tar

MAINTAINER=	demon@FreeBSD.org

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty

WRKSRC=		${WRKDIR}/GGSD

USE_GTK=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ggsd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ggsd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ggsd
	${INSTALL_DATA} ${WRKSRC}/example.scr ${PREFIX}/share/doc/ggsd
.endif

.include <bsd.port.mk>
