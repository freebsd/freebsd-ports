# New ports collection makefile for:	deltup
# Date created:		2005-05-18
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deltup
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Source delta update program

RUN_DEPENDS=	bdelta:${PORTSDIR}/misc/bdelta

USE_OPENSSL=	yes
ALL_TARGET=	deltup
PLIST_FILES=	bin/deltup \
		bin/bzip2_old
MAN1=		deltup.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deltup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deltup.1 ${PREFIX}/man/man1
.if !exists(${PREFIX}/bin/bzip2_old)
	@${LN} -s ${BZIP2_CMD} ${PREFIX}/bin/bzip2_old
.endif

.include <bsd.port.mk>
