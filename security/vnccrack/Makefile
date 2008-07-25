# New ports collection makefile for:	vnccrack
# Date created:		2006-08-19
# Whom:			Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	vnccrack
PORTVERSION=	1.0.0
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/vnccrack/
DISTNAME=	VNCcrack-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A fast offline password cracker for VNC passwords

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

SUB_FILES+=	pkg-message

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vnccrack ${PREFIX}/bin/vnccrack

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/readme.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
