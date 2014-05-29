# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	exact
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://adju.st/dist/exact/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that implements POP Before SMTP Relay Authentication

MAILUSER?=	mailnull
MAILGROUP?=	mailnull
MAILLOG?=	/var/log/maillog
EXACTDIR?=	/var/exact
PLIST_SUB+=	MAILUSER=${MAILUSER} MAILGROUP=${MAILGROUP} EXACTDIR=${EXACTDIR}

FETCH_CMD=	/usr/bin/fetch -Rr
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${MAILUSER} \
		--with-group=${MAILGROUP} \
		--with-watch=${MAILLOG}

NO_STAGE=	yes
pre-install:
	@${SED} -e "s,/usr/local/var,/var,g; s,/state,,g" ${WRKSRC}/exact.conf > ${WRKSRC}/exact.conf.sample
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g; s,%%EXACTDIR%%,${EXACTDIR},g" ${FILESDIR}/exact.sh > ${WRKSRC}/exact.sh

do-install:
	${MKDIR} ${EXACTDIR}
	${CHOWN} ${MAILUSER}:${MAILGROUP} ${EXACTDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/exact ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/exact.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/exact.conf.sample ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/exact.conf.5 ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/exact.8 ${MAN8PREFIX}/man/man8

MAN5=		exact.conf.5
MAN8=		exact.8

.include <bsd.port.mk>
