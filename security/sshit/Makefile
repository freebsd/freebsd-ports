# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sshit
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://anp.ath.cx/sshit/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks for SSH/FTP bruteforce and blocks given IPs

RUN_DEPENDS=	p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-IPC-Shareable>=0:${PORTSDIR}/devel/p5-IPC-Shareable \
		p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/sshit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf-dist

.include <bsd.port.mk>
