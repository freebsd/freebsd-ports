# New ports collection makefile for:	gutenfetch
# Date created:		22-Aug-2001
# Whom:			Russell Francis
#
# $FreeBSD$
#

PORTNAME=	gutenfetch
PORTVERSION=	1.5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	johntabularasa@users.sf.net
COMMENT=	Fetch listings and books from Project Gutenberg

LIB_DEPENDS=	gutenfetch:${PORTSDIR}/devel/libgutenfetch

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN1=		gutenfetch.1
PLIST_FILES=	bin/gutenfetch

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gutenfetch
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.mk>
