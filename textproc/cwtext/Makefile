# ex:ts=8
# New ports collection makefile for:	cwtext
# Date created:			Nov 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cwtext
PORTVERSION=	0.90
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	ALL

post-patch:
	@${REINPLACE_CMD} -e "s,^PREFIX,#PREFIX,g ; \
		s,gcc,${CC} ${CFLAGS},g" ${WRKSRC}/${MAKEFILE}

do-install:
.for file in cwpcm cwtext
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
