# New ports collection makefile for:	massadmin
# Date created:				27 Sep 2010
# Whom:					Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	massadmin
PORTVERSION=	2.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sklauder@trimind.de
COMMENT=	Send system commands to a group of remote servers simultaneously

RUN_DEPENDS=	p5-Expect>=1.21:${PORTSDIR}/lang/p5-Expect \
		p5-Net-Telnet>=3.03:${PORTSDIR}/net/p5-Net-Telnet \
		p5-Net-Ping>=2.36:${PORTSDIR}/net/p5-Net-Ping \
		p5-Proc-Queue>=1.23:${PORTSDIR}/devel/p5-Proc-Queue \
		p5-IO-Tty>=1.08:${PORTSDIR}/devel/p5-IO-Tty

NO_BUILD=	yes
USE_PERL5=	yes

LICENSE=	GPLv3

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		massadmin.1
.endif
PLIST_FILES=	bin/massadmin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/massadmin ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1)
.endif

.include <bsd.port.mk>
