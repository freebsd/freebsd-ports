# New ports collection makefile for:   quoted
# Date created:        1 December 2004
# Whom:                Bob Frazier
#
# $FreeBSD$
#

PORTNAME=	quoted
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.mrp3.com/webutil/

MAINTAINER=	bobf@mrp3.com
COMMENT=	Easily configured QOTD daemon with over 130 good quality quotes

MAN1=		quoted.1
MANCOMPRESSED=	no
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

USE_RC_SUBR=	 yes
RC_SUFX=	.sh

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g; s,/etc/rc.subr,${RC_SUBR},g;" ${WRKSRC}/quoted.sh.rc.freebsd

.include <bsd.port.mk>
