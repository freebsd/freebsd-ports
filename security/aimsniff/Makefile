# Created by: Andrew Marks <andrew@amrx.net>
# $FreeBSD$

PORTNAME=	aimsniff
PORTVERSION=	0.9d
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/AIM%20Sniff/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOL Instant Messenger Sniffing and Reading Tool

LICENSE=	GPLv2 # only

RUN_DEPENDS=	p5-Net-Pcap>=0:net/p5-Net-Pcap\
		p5-NetPacket>=0:net/p5-NetPacket\
		p5-DBI>=0:databases/p5-DBI\
		p5-Unicode-String>=0:converters/p5-Unicode-String\
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon\
		p5-Proc-Simple>=0:devel/p5-Proc-Simple\
		p5-Unix-Syslog>=0:sysutils/p5-Unix-Syslog

USES=		perl5 shebangfix
SHEBANG_FILES=	aimSniff.pl
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/aimsniff
PORTDOCS=	README table.struct rc.aimsniff

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aimSniff.pl ${STAGEDIR}${PREFIX}/bin/aimsniff

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
