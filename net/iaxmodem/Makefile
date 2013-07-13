# Created by: Filippo Natali <filippo.natali@gmail.com>
# $FreeBSD$

PORTNAME=	iaxmodem
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	net comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	stucchi@gufi.org
COMMENT=	Software modem that connects to IAX channel

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

BROKEN=		Does not build

MAN1=		iaxmodem.1
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
USE_RC_SUBR=	iaxmodem
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/etc|${PREFIX}/etc|g" ${WRKSRC}/iaxmodem.1
	@${REINPLACE_CMD} -e "s|/etc/iaxmodem|${PREFIX}/etc/iaxmodem|g" ${WRKSRC}/iaxmodem.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iaxmodem ${PREFIX}/sbin/ && \
	${MKDIR} ${PREFIX}/etc/iaxmodem && \
	${MKDIR} /var/log/iaxmodem && \
	${MKDIR} ${EXAMPLESDIR} && \
	${INSTALL_DATA} ${WRKSRC}/config.ttyIAX ${EXAMPLESDIR}/ && \
	${INSTALL_DATA} ${WRKSRC}/iaxmodem-cfg.ttyIAX ${EXAMPLESDIR}/
	${INSTALL_MAN} ${WRKSRC}/iaxmodem.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/FAQ ${WRKSRC}/CHANGES ${DOCSDIR}
.endif

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
