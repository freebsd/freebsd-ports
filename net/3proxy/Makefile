# New ports collection makefile for:    3proxy
# Date created:         2003 July 25
# Whom:                 tim@relay.nnn.tstu.ru
#
# $FreeBSD$
#

PORTNAME=	3proxy
PORTVERSION=	0.4.5b
CATEGORIES=	net
MASTER_SITES=	http://www.security.nnov.ru/soft/3proxy/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
MAKEFILE=	Makefile.unix
MAKE_ENV=	CC="${CC}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
post-patch:
	${REINPLACE_CMD} -e "s|%%CFLAGS%%|${CFLAGS}|" \
		${WRKDIR}/Makefile.unix

do-install:
.for i in 3proxy dighosts mycrypt pop3p proxy socks tcppm udppm
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/3proxy.cfg.sample ${PREFIX}/etc
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/3proxy.sh \
		> ${WRKSRC}/3proxy.sh
	${INSTALL_SCRIPT} ${WRKSRC}/3proxy.sh ${PREFIX}/etc/rc.d/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in License Readme Release.notes
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
