# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sshit
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://anp.ath.cx/sshit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks for SSH/FTP bruteforce and blocks given IPs

BROKEN=		unfetchable

RUN_DEPENDS=	p5-Unix-Syslog>=0:sysutils/p5-Unix-Syslog \
		p5-IPC-Shareable>=0:devel/p5-IPC-Shareable \
		p5-Proc-PID-File>=0:devel/p5-Proc-PID-File

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	sshit

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf-dist

.include <bsd.port.mk>
