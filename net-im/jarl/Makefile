# Created by: dd
# $FreeBSD$

PORTNAME=	jarl
PORTVERSION=	0.5001
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	SF
DISTNAME=	Jarl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl/Tk Jabber client

LICENSE=	GPLv2

RUN_DEPENDS=	ptksh:x11-toolkits/p5-Tk \
		p5-Net-Jabber>=0:net-im/p5-Net-Jabber

USES=		perl5
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/jarl
	${FIND} ${WRKSRC}/lib -name "*.orig" -delete

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/bitmaps
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC}/bitmaps && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/bitmaps
	${INSTALL_SCRIPT} ${WRKSRC}/jarl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
