# New ports collection makefile for:	googlebook_dl
# Date created:		2010-12-02
# Whom:			<spam@rm-rf.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	googlebook_dl
PORTVERSION=	20100502
CATEGORIES=	www
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	A command-line utility for downloading books from Google Books

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
