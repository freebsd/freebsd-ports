# New ports collection makefile for: aimsniff
# Date created:        4 December 2004
# Whom:                Andrew Marks (andrew@amrx.net)
#
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

OPTIONS=	SUID_ROOT "Install aimsniff with set-uid bit" off

PORTDOCS=	README table.struct rc.aimsniff

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/aimsniff

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/GDBM_File.pm)
#IGNORE=		You need perl compiled with GDBM support
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aimSniff.pl ${PREFIX}/bin/aimsniff
.if defined(WITH_SUID_ROOT)
	${CHMOD} u+s ${PREFIX}/bin/aimsniff
.else
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
