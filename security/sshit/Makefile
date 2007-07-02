# New ports collection makefile for:	sshit
# Date created:				18 December 2005
# Whom:					Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	sshit
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://anp.ath.cx/sshit/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Checks for SSH/FTP bruteforce and blocks given IPs

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/IPC/Shareable.pm:${PORTSDIR}/devel/p5-IPC-Shareable \
		${SITE_PERL}/Proc/PID/File.pm:${PORTSDIR}/devel/p5-Proc-PID-File

NO_BUILD=	yes
USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf-dist

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf-dist ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
