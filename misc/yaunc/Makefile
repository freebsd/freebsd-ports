# New ports collection makefile for:	yaunc
# Date created:		5 March 2000
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	yaunc
PORTVERSION=	1.00
CATEGORIES=	misc
MASTER_SITES=	http://www.redterror.net/code/yaunc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another uptimes.net client

USE_REINPLACE=	yes
ALL_TARGET=	bsd
CFLAGS+=	-DCONFFILE=\\\"${PREFIX}/etc/yaunc.conf\\\"

MAN1=		yaunc.1

post-patch:
	@${CP} -f ${FILESDIR}/startup ${WRKSRC}/yaunc.sh
.for file in yaunc.1 yaunc.sh
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaunc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yaunc.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} -m 600 ${WRKSRC}/yaunc.conf ${PREFIX}/etc/yaunc.conf.sample
	${INSTALL_SCRIPT} -m 755 ${WRKSRC}/yaunc.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
