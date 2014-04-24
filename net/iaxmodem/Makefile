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

PLIST_FILES=	sbin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGES FAQ README
PORTEXAMPLES=	config.ttyIAX iaxmodem-cfg.ttyIAX

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${PERL} -0pi.bak -e "s|for ac_header in tgmath\.h.*?done||s" \
		${WRKSRC}/lib/spandsp/configure
	@${REINPLACE_CMD} -e "s|/etc/iaxmodem|${PREFIX}&|" \
		${WRKSRC}/iaxmodem.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iaxmodem ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/iaxmodem.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
