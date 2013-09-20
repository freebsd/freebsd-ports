# Created by: bugghy <bugghy@SAFe-mail.net>
# $FreeBSD$

PORTNAME=	sud
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Execute processes with special privileges in a nosuid environment

GNU_CONFIGURE=	yes
MAN1=		sud.1 suz.1 ilogin.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/ilogin.1 ${WRKSRC}/sud.1 ${WRKSRC}/login/login.c ${WRKSRC}/sud/main.c
	@${REINPLACE_CMD} -e 's|/usr/sbin/ilogin|${PREFIX}/ilogin| ; s|/usr/bin/ls|/bin/ls|' \
		${WRKSRC}/miscs/sud.conf.sample

post-install:
	${INSTALL_MAN} ${WRKSRC}/sud.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/suz.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ilogin.1 ${MAN1PREFIX}/man/man1

.for i in issue.suz motd.suz sud.conf.sample
	${INSTALL_DATA} ${WRKSRC}/miscs/${i} ${PREFIX}/etc
.endfor
	@if [ ! -f ${PREFIX}/etc/sud.conf ]; then \
		${CP} -p ${PREFIX}/etc/sud.conf.sample ${PREFIX}/etc/sud.conf ; \
	fi

.include <bsd.port.post.mk>
