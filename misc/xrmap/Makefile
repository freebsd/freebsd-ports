# New ports collection makefile for:	xrmap
# Date created:				25 Dec 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	xrmap
PORTVERSION=	2.10
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
USE_XPM=	yes

MAN1=	xrmap.1

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${PERL} -pi -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/Imakefile

post-install:
	@${SED} "s,%%PREFIX%%,${PREFIX}," < ${FILESDIR}/pkg-message.in > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
