# New ports collection makefile for:	distributed.net-v2personalproxy
# Version required:     308
# Date created:         31 Oct 1999
# Whom:                 globalpanic@gmx.net
#
# $FreeBSD$
#

DISTNAME=	proxyper308-freebsd3-elf-x86
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/proxyper-rc5des/ \
		http://http.distributed.net/pub/dcti/proxyper-rc5des/

MAINTAINER=	globalpanic@gmx.net

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

.if ${OSVERSION} < 220000
BROKEN=		"No version is built for your system."
.elif ${OSVERSION} < 300000
BROKEN=		"No version is currently available for your system.  Please try again later."
.endif

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/proxyper/
LIBDIR=		${PREFIX}/etc/rc.d/
WRKSRC=		${WRKDIR}

CLIENTUID=	nobody
CLIENTGID=	daemon

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi
	${INSTALL} -c -m 711 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/proxyper ${BINDIR}
	${SED} s#CHANGETHIS#${BINDIR}# < ${FILESDIR}/proxyper.sh > ${WRKSRC}/proxyper.sh
	${INSTALL} -c -m 711 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/proxyper.sh ${BINDIR}
	${INSTALL} -c -m 644 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/proxyper.ini ${BINDIR}
	${INSTALL} -c -m 644 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/ChangeLog.txt ${BINDIR}
	${INSTALL} -c -m 644 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/Readme.txt ${BINDIR}
	${INSTALL} -c -m 644 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/Readme.txt ${BINDIR}
	${CHOWN} ${CLIENTUID}:${CLIENTGID} ${BINDIR}
	${CHMOD} 755 ${BINDIR}
	${LN} -s ${BINDIR}proxyper.sh ${LIBDIR}proxyper.sh

.include <bsd.port.mk>
