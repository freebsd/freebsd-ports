# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	dvbsnoop
PORTVERSION=	1.4.50
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	DVB stream analyzer / MPEG analyzer

DVB_HEADERS=	dmx.h frontend.h

GNU_CONFIGURE=	yes
CFLAGS+=	-I${WRKSRC}
USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	${MKDIR} ${WRKSRC}/linux/dvb
	cd ${FILESDIR}; ${CP} ${DVB_HEADERS} ${WRKSRC}/linux/dvb

.include <bsd.port.post.mk>
