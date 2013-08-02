# Created by: Filippo Natali <filippo.natali@gmail.com>
# $FreeBSD$

PORTNAME=	iaxmodem
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	net comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	stucchi@gufi.org
COMMENT=	Software modem that connects to IAX channel

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

USES=		perl5
USE_PERL5=	patch
HAS_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	sbin/${PORTNAME}
PORTDOCS=	CHANGES FAQ README
PORTEXAMPLES=	config.ttyIAX iaxmodem-cfg.ttyIAX
MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${PERL} -0pi.bak -e "s|for ac_header in tgmath\.h.*?done||s" \
		${WRKSRC}/lib/spandsp/configure
	@${REINPLACE_CMD} -e "s|/etc/iaxmodem|${PREFIX}&|" \
		${WRKSRC}/iaxmodem.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iaxmodem ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/iaxmodem.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
