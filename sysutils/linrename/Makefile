# Ports collection makefile for:	linrename
# Date created:				December 13 2006
# Whom:					Jonathan Liu <Net147@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	linrename
PORTVERSION=	2.12r
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	Net147@hotmail.com
COMMENT=	Rename multiple files using substitution

PLIST_FILES=	bin/linrename
MAN1=		linrename.1

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GCC=	3.4+

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -lintl -I${WRKSRC}/lib
EXTRACT_AFTER_ARGS=	| tar -xf - \
			${DISTNAME}/lib/nls.h \
			${DISTNAME}/misc-utils/rename.1 \
			${DISTNAME}/misc-utils/rename.c

.include <bsd.port.pre.mk>

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/misc-utils/rename.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/misc-utils/rename.1 ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.post.mk>
