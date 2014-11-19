# Created by: Andrew Marks <andrew@amrx.net>
# $FreeBSD$

PORTNAME=	aimsniff
PORTVERSION=	0.9d
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/AIM%20Sniff/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOL Instant Messenger Sniffing and Reading Tool

RUN_DEPENDS=	p5-Net-Pcap>=0:${PORTSDIR}/net/p5-Net-Pcap\
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket\
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI\
		p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String\
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon\
		p5-Proc-Simple>=0:${PORTSDIR}/devel/p5-Proc-Simple\
		p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog

OPTIONS_DEFINE=	SUID_ROOT DOCS
SUID_ROOT_DESC=	Install aimsniff with set-uid bit

PORTDOCS=	README table.struct rc.aimsniff

USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/aimsniff

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aimSniff.pl ${STAGEDIR}${PREFIX}/bin/aimsniff
.if ${PORT_OPTIONS:MSUID_ROOT}
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/aimsniff
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
