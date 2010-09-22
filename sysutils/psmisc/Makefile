# New ports collection makefile for:    psmisc
# Date created:         10 March 1998
# Whom:                 rantapaa@uswest.net
#
# $FreeBSD$
#

PORTNAME=	psmisc
PORTVERSION=	22.12
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A port of the Linux pstree, killall and pidof commands

CONFLICTS=	pidof-[0-9]* pstree-2.[0-9]*

CONFIGURE_ARGS=	--disable-nls
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		killall.1 pstree.1
PLIST_FILES=	bin/killall bin/pidof bin/pstree bin/pstree.x11

post-patch:
	@${REINPLACE_CMD} -e '/^#define COMM_LEN / s|16|254|' ${WRKSRC}/src/comm.h

post-install:
	@${LN} -fs killall ${PREFIX}/bin/pidof

.include <bsd.port.mk>
