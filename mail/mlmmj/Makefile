# New ports collection makefile for:   mlmmj
# Date created:        12 june 2004
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	mlmmj
PORTVERSION=	0.8.3
CATEGORIES=	mail
MASTER_SITES=	http://mlmmj.mmj.dk/files/

MAINTAINER=	xi@borderworlds.dk
COMMENT=	Mailing list managing made joyful

USE_BZIP2=	yes
USE_REINPLACE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/mlmmj-make-ml.sh

post-install:
	@${MKDIR} ${PREFIX}/share/mlmmj/listtexts
	@${INSTALL_DATA} ${WRKSRC}/listtexts/* ${PREFIX}/share/mlmmj/listtexts

.include <bsd.port.mk>
