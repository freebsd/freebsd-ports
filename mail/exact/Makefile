# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	exact
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://adju.st/dist/exact/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that implements POP Before SMTP Relay Authentication

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

MAILUSER?=	mailnull
MAILGROUP?=	mailnull
MAILLOG?=	/var/log/maillog
EXACTDIR?=	/var/exact
PLIST_SUB+=	MAILUSER=${MAILUSER} MAILGROUP=${MAILGROUP} EXACTDIR=${EXACTDIR}

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${MAILUSER} \
		--with-group=${MAILGROUP} \
		--with-watch=${MAILLOG}

pre-install:
	@${SED} -e "s,/usr/local/var,/var,g; s,/state,,g" ${WRKSRC}/exact.conf > ${WRKSRC}/exact.conf.sample
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g; s,%%EXACTDIR%%,${EXACTDIR},g" ${FILESDIR}/exact.sh > ${WRKSRC}/exact.sh

do-install:
	@${MKDIR} ${STAGEDIR}${EXACTDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/exact ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/exact.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/exact.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/exact.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/exact.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
