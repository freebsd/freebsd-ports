# New ports collection makefile for:   yaunc
# Date created:        5 March 2000
# Whom:                nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	yaunc
PORTVERSION=	0.02
CATEGORIES=	misc
MASTER_SITES=	http://www.redterror.net/code/yaunc/

MAINTAINER=	nsayer@freebsd.org

WRKSRC=		${WRKDIR}/yaunc

MAN1=		yaunc.1

do-install:
	( cd ${WRKSRC} ;\
	${INSTALL_PROGRAM} yaunc ${PREFIX}/bin ;\
	${INSTALL_DATA} -m 600 yaunc.conf ${PREFIX}/etc/yaunc.conf.sample ;\
	${INSTALL_MAN} yaunc.man ${PREFIX}/man/man1/yaunc.1 ;\
	${SED} s+%%PREFIX%%+${PREFIX}+g < ${FILESDIR}/startup > \
		${PREFIX}/etc/rc.d/yaunc.sh ;\
	chmod 755 ${PREFIX}/etc/rc.d/yaunc.sh )

.include <bsd.port.mk>
