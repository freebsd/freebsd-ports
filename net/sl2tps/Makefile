# New ports collection makefile for:	sl2tps
# Date created:				4 Jul 2004
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	sl2tps
PORTVERSION=	0.4.2
CATEGORIES=	net
MASTER_SITES=	SF/libpdel/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple L2TP server based on libpdel(3) and netgraph(4)

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	pdel.0:${PORTSDIR}/devel/libpdel

MANCOMPRESSED=	maybe
MAN1=		sl2tps.1
PLIST_FILES=	bin/sl2tps %%ETCDIR%%/config.xml.sample
PLIST_DIRS=	%%ETCDIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${PREFIX}/include|$${LOCALBASE}/include|g ; \
		 s|-pthread|${PTHREAD_LIBS}|g ; \
		 /-g/s|^CFLAGS|#CFLAGS|g ; \
		 s|$${PREFIX}/lib|$${LOCALBASE}/lib|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
