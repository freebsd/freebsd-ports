# New ports collection makefile for:	distributed.net-v2personalproxy
# Date created:         31 Oct 1999
# Whom:                 globalpanic@gmx.net
#
# $FreeBSD$
#

PORTNAME=	proxyper-freebsd3-elf-x86
PORTVERSION=	319c
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/proxyper-rc5des/ \
		http://http.distributed.net/pub/dcti/proxyper-rc5des/
DISTNAME=	proxyper${PORTVERSION}-freebsd-x86

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

SHAREOWN=	${PROXYUID}
SHAREGRP=	${PROXYGID}
SHAREMODE=	644

do-build:
	${SED} s#CHANGETHIS#${BINDIR}# < ${FILESDIR}/proxyper.sh > ${WRKSRC}/proxyper.sh

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/proxyper ${BINDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/proxyper.sh ${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/proxyper.ini ${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog.txt ${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/Readme.txt ${BINDIR}
	${CHOWN} ${PROXYUID}:${PROXYGID} ${BINDIR}
	${CHMOD} 755 ${BINDIR}
	${LN} -sf ${BINDIR}proxyper.sh ${LIBDIR}proxyper.sh

.include <bsd.port.post.mk>
