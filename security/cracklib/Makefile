# New ports collection makefile for:	cracklib
# Date created:				22 April 2000
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	cracklib
PORTVERSION=	2.8.18
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Password-checking library

LICENSE=	LGPL21

MAN3=		cracklib.3
MLINKS=		cracklib.3 FascistCheck.3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-default-dict=${PREFIX}/libdata/${PORTNAME}

post-install:
	${INSTALL_MAN} ${FILESDIR}/cracklib.3 ${MAN3PREFIX}/man/man3/
	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/pw_dict* ${PREFIX}/libdata/${PORTNAME}/

.include <bsd.port.mk>
