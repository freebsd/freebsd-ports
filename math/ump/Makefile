# New ports collection makefile for:	ump
# Date created:		2006-04-20
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	ump
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	u-m-p

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graphical, easy to use math program

CONFLICTS=	ump-1.[0-9]*
LATEST_LINK=	math-ump

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GL=		yes
USE_X_PREFIX=	yes

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV+=	CXX="${CXX}" CC="${CC}" DATADIR="${DATADIR}" \
		X11BASE="${X11BASE}"

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
