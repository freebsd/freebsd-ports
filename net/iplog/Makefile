# Created by: Dominik Rothert <dr@domix.de>
# $FreeBSD$

PORTNAME=	iplog
PORTVERSION=	2.2.3
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	SF/ojnk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	udo@schweigert-muc.de
COMMENT=	TCP/IP traffic logging tool

DEPRECATED=	Unmaintained and dead upstream. Does not build with modern compilers.
EXPIRATION_DATE=2020-12-18

USES=		gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

USE_RC_SUBR=	iplog

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1300000
IGNORE = The iplog port is broken for FreeBSD 13.x and above
.endif

post-patch:
.for FILE in example-iplog.conf iplog.8 iplog.conf.5 src/iplog.h
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${STAGEDIR}${PREFIX}/etc/iplog.conf.sample

.include <bsd.port.mk>
