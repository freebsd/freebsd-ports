# New ports collection makefile for:	distributed.net-v2personalproxy
# Date created:         31 Oct 1999
# Whom:                 globalpanic@gmx.net
#
# $FreeBSD$
#

PORTNAME=	proxyper-freebsd3-elf-x86
PORTVERSION=	333
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/proxyper/ \
		http://http.distributed.net/pub/dcti/proxyper/
DISTNAME=	proxyper${PORTVERSION}-freebsd-x86

MAINTAINER=	dbaker@FreeBSD.org
COMMENT=	The official distributed.net v2 personal proxy

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

.if ${OSVERSION} < 300000
IGNORE=		"This port requires FreeBSD 3.X or greater."
.endif

NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net/proxy/
LIBDIR=		${PREFIX}/etc/rc.d/

PROXYUID=	nobody
PROXYGID=	daemon

SHAREOWN=	${PROXYUID}
SHAREGRP=	${PROXYGID}
SHAREMODE=	644

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/proxyper ${BINDIR}
	${REINPLACE_CMD} s+CHANGETHIS+${BINDIR}+ ${FILESDIR}/proxyper.sh > ${WRKSRC}/proxyper.sh
	${INSTALL_SCRIPT} ${WRKSRC}/proxyper.sh ${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/proxyper.ini ${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog.txt ${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/manual.html ${BINDIR}
	${CHOWN} ${PROXYUID}:${PROXYGID} ${BINDIR}
	${CHMOD} 755 ${BINDIR}
	${LN} -sf ${BINDIR}proxyper.sh ${LIBDIR}proxyper.sh

.include <bsd.port.post.mk>
