# New ports collection makefile for:    3proxy
# Date created:         2003 July 25
# Whom:                 tim@relay.nnn.tstu.ru
#
# $FreeBSD$
#

PORTNAME=	3proxy
PORTVERSION=	0.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.security.nnov.ru/soft/3proxy/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)

NO_WRKSUBDIR=	yes
USE_RC_SUBR=	yes
MAKEFILE=	Makefile.unix
MAKE_ENV=	CC="${CC}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN3=	3proxy.conf.3
MAN8=	3proxy.8 ftppr.8 pop3p.8 proxy.8 socks.8 tcppm.8 udppm.8

RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/3proxy.sh.in > ${WRKSRC}/3proxy.sh

post-patch:
	${REINPLACE_CMD} -e "s|%%CFLAGS%%|${CFLAGS}|" \
		${WRKDIR}/Makefile.unix

do-install:
.for i in 3proxy dighosts ftppr mycrypt pop3p proxy socks tcppm udppm
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i} ${PREFIX}/bin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/cfg/3proxy.cfg.sample ${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/3proxy.sh ${PREFIX}/etc/rc.d/
	${INSTALL_MAN} ${WRKSRC}/man/${MAN3} ${PREFIX}/man/man3
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man8
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in License Readme Release.notes
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
