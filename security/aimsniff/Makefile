# New ports collection makefile for: aimsniff
# Date created:        4 December 2004
# Whom:                Andrew Marks (andrew@amrx.net)
#
# $FreeBSD$

PORTNAME=	aimsniff
PORTVERSION=	0.9d
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aimsniff
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andrew@amrx.net
COMMENT=	AOL Instant Messanger Sniffing and Reading Tool

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/Pcap.pm:${PORTSDIR}/net/p5-Net-Pcap\
		${SITE_PERL}/NetPacket.pm:${PORTSDIR}/net/p5-NetPacket\
		${SITE_PERL}/${PERL_ARCH}/auto/DBI/DBI.so:${PORTSDIR}/databases/p5-DBI\
		${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String\
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon\
		${SITE_PERL}/Proc/Simple.pm:${PORTSDIR}/devel/p5-Proc-Simple\
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog

OPTIONS=	SUID_ROOT "Install aimsniff with set-uid bit" off

PORTDOCS=	README table.struct rc.aimsniff

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/aimsniff

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/GDBM_File.pm)
#IGNORE=		"You need perl compiled with GDBM support"
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
