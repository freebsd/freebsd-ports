# New ports collection makefile for:	yafic
# Date created:		20 August 2001
# Whom:			asaddi@philosophysw.com
#
# $FreeBSD$
#

PORTNAME=	yafic
PORTVERSION=	1.0.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	allan@saddi.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LDFLAGS="-static"

MAN1=		yafic.1
MAN5=		yafic.conf.5

post-install:
	@${MKDIR} ${PREFIX}/share/examples/yafic
	@${CP} ${FILESDIR}/yafic.conf.sample ${PREFIX}/share/examples/yafic
	@${ECHO}
	@${SED} -e "s%@@PREFIX@@%${PREFIX}%g" ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
