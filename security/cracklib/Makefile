# Created by: ajk@iu.edu
# $FreeBSD$

PORTNAME=	cracklib
PORTVERSION=	2.8.22
CATEGORIES=	security
MASTER_SITES=	SF \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Password-checking library

LICENSE=	LGPL21

MAN3=		${PORTNAME}.3
MLINKS=		${PORTNAME}.3 FascistCheck.3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-default-dict=${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=	PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
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
