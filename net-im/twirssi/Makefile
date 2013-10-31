# $FreeBSD$

PORTNAME=	twirssi
PORTVERSION=	2.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://twirssi.com/
EXTRACT_SUFX=	.pl
EXTRACT_ONLY=

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Twitter script to irssi

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-Twitter>=0:${PORTSDIR}/net/p5-Net-Twitter \
		p5-WWW-Shorten>=0:${PORTSDIR}/www/p5-WWW-Shorten \
		p5-WWW-Shorten-Bitly>=0:${PORTSDIR}/www/p5-WWW-Shorten-Bitly

OPTIONS_SINGLE=	IRSSIVER
OPTIONS_SINGLE_IRSSIVER=PROD DEVEL
OPTIONS_DEFAULT=PROD
PROD_DESC=	Use production irc/irssi port
DEVEL_DESC=	Use development irc/irssi-devel port

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPROD}
RUN_DEPENDS+=	irssi:${PORTSDIR}/irc/irssi
.endif

.if ${PORT_OPTIONS:MDEVEL}
RUN_DEPENDS+=	irssi:${PORTSDIR}/irc/irssi-devel
.endif

SUB_FILES=	pkg-message

NO_BUILD=	yes
PLIST_FILES=	%%DATADIR%%/${PORTNAME}.pl
PLIST_DIRS=	%%DATADIR%%

post-extract:
	@${MKDIR} ${WRKSRC}
	@${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.pl \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_SCRIPT} -v ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
