# New ports collection makefile for:	distributed.net-v2personalproxy
# Version required:     308
# Date created:         31 Oct 1999
# Whom:                 globalpanic@gmx.net
#
# $FreeBSD$
#

DISTNAME=	proxyper313-freebsd-x86
PKGNAME=	proxyper-freebsd3-elf-x86-313
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/proxyper-rc5des/ \
		http://http.distributed.net/pub/dcti/proxyper-rc5des/

MAINTAINER=	dbaker@FreeBSD.org

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

.if ${OSVERSION} < 220000
BROKEN=		"No version is built for your system."
.elif ${OSVERSION} < 300000
BROKEN=		"No version is currently available for your system.  Please try again later."
.endif

NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net/proxy/
LIBDIR=		${PREFIX}/etc/rc.d/

PROXYUID=	nobody
PROXYGID=	daemon

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi
	${INSTALL} -c -m 711 -o ${PROXYUID} -g ${PROXYGID} ${WRKSRC}/proxyper ${BINDIR}
	${SED} s#CHANGETHIS#${BINDIR}# < ${FILESDIR}/proxyper.sh > ${WRKSRC}/proxyper.sh
	${INSTALL} -c -m 711 -o ${PROXYUID} -g ${PROXYGID} ${WRKSRC}/proxyper.sh ${BINDIR}
	${INSTALL} -c -m 644 -o ${PROXYUID} -g ${PROXYGID} ${WRKSRC}/proxyper.ini ${BINDIR}
	${INSTALL} -c -m 644 -o ${PROXYUID} -g ${PROXYGID} ${WRKSRC}/ChangeLog.txt ${BINDIR}
	${INSTALL} -c -m 644 -o ${PROXYUID} -g ${PROXYGID} ${WRKSRC}/Readme.txt ${BINDIR}
	${INSTALL} -c -m 644 -o ${PROXYUID} -g ${PROXYGID} ${WRKSRC}/Readme.txt ${BINDIR}
	${CHOWN} ${PROXYUID}:${PROXYGID} ${BINDIR}
	${CHMOD} 755 ${BINDIR}
	if [ ! -f ${LIBDIR}/proxyper.sh ]; then \
		${LN} -s ${BINDIR}proxyper.sh ${LIBDIR}proxyper.sh; \
	fi

.include <bsd.port.post.mk>
