# Created by: Valerio Daelli <valerio.daelli@gmail.com>
# $FreeBSD$

PORTNAME=	sqlninja
DISTVERSION=	0.2.6
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sql Server exploit toolkit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-Pcap>=0:net/p5-Net-Pcap \
		p5-Net-RawIP>=0:net/p5-Net-RawIP \
		p5-NetPacket>=0:net/p5-NetPacket

USES=		perl5 tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/scripts
	${MKDIR} ${STAGEDIR}${ETCDIR}/apps
.for i in sqlninja
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in churrasco.scr dnstun.scr nc.scr
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${i} ${STAGEDIR}${ETCDIR}/scripts
.endfor
.for i in churrasco.exe dnstun.exe nc.exe
	${INSTALL_SCRIPT} ${WRKSRC}/apps/${i} ${STAGEDIR}${ETCDIR}/apps
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in sqlninja-howto.html sqlninja.conf.example
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
