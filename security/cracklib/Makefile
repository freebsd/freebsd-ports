# New ports collection makefile for:	cracklib
# Date created:				22 April 2000
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	cracklib
PORTVERSION=	2.8.18
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Password-checking library

LICENSE=	LGPL21

MAN3=		${PORTNAME}.3
MLINKS=		${PORTNAME}.3 FascistCheck.3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-default-dict=${PREFIX}/libdata/${PORTNAME}

.ifdef(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/${MAN3} ${MAN3PREFIX}/man/man3/
	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/pw_dict* ${PREFIX}/libdata/${PORTNAME}/

.include <bsd.port.mk>
