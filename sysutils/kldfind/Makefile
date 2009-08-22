# New ports collection makefile for:   kldfind
# Date created:        15 July 2006
# Whom:                Ricardo A. Reis <ricardo.areis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kldfind
PORTVERSION=	0.61
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ricardo.areis@gmail.com
COMMENT=	Find kernel modules by string

NO_BUILD=	yes
USE_BZIP2=	yes

MAN8=		kldfind.8
PLIST_FILES=	sbin/kldfind

do-install:
	@${ECHO_MSG} "===>  Installing kldfind."
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${PREFIX}/sbin/${PORTNAME}
	@${ECHO_MSG} "===>  Installing man page."
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
