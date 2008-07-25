# New ports collection makefile for:	ump
# Date created:		2006-04-20
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	ump
PORTVERSION=	0.8.6
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/u-m-p

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graphical, easy to use math program

CONFLICTS=	ump-1.[0-9]*
LATEST_LINK=	math-ump

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GL=		glu

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV+=	DATADIR="${DATADIR}"

FIND_DIRS=	-type d
FIND_DATA=	-type f

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		requires trunc(3) and round(3)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/main.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ump.conf ${PREFIX}/etc/ump.conf.dist
.if !exists(${PREFIX}/etc/ump.conf)
	${INSTALL_DATA} ${WRKSRC}/ump.conf ${PREFIX}/etc
.endif

.include <bsd.port.post.mk>
