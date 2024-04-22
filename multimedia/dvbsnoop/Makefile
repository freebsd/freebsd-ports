PORTNAME=	dvbsnoop
PORTVERSION=	1.4.50
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	DVB stream analyzer / MPEG analyzer
WWW=		https://dvbsnoop.sourceforge.net/

DVB_HEADERS=	dmx.h frontend.h

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CFLAGS+=	-I${WRKSRC}
USES=		gmake

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/dvbsnoop.1.gz

.include <bsd.port.pre.mk>

post-patch:
	${MKDIR} ${WRKSRC}/linux/dvb
	cd ${FILESDIR}; ${CP} ${DVB_HEADERS} ${WRKSRC}/linux/dvb

.include <bsd.port.post.mk>
