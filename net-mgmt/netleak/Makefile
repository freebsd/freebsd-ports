# Created by: Vaida Bogdan
# $FreeBSD$

PORTNAME=	netleak
PORTVERSION=	0.1a
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to detect connectivity between network segments

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Net-PcapUtils>=0:net/p5-Net-PcapUtils \
		p5-NetPacket>=0:net/p5-NetPacket \
		p5-Mail-Sendmail>=0:mail/p5-Mail-Sendmail \
		p5-Net-RawIP>=0:net/p5-Net-RawIP \
		p5-IO-Interface>=0:net/p5-IO-Interface \
		p5-NetAddr-IP>0:net-mgmt/p5-NetAddr-IP

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
SHEBANG_FILES= 	netleak netleakd

PORTDOCS=	BUGS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
