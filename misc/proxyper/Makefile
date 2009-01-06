# New ports collection makefile for:	distributed.net-v2personalproxy
# Date created:         31 Oct 1999
# Whom:                 globalpanic@gmx.net
#
# $FreeBSD$
#

PORTNAME=	proxyper
PORTVERSION=	343
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/proxyper/ \
		http://http.distributed.net/pub/dcti/proxyper/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	The official distributed.net v2 personal proxy

ONLY_FOR_ARCHS=	i386

USE_RC_SUBR=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net/proxy

PROXYUSER=	nobody
PROXYGROUP=	daemon

SHAREOWN=	${PROXYUSER}
SHAREGRP=	${PROXYGROUP}
SHAREMODE=	644

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700055
DISTNAME=	proxyper${PORTVERSION}-freebsd7-x86
.else
DISTNAME=	proxyper${PORTVERSION}-freebsd4-x86
.endif

post-extract:
	@${SED} -e 's#%%BINDIR%%#${BINDIR}#'g \
		-e 's#%%RC_SUBR%%#${RC_SUBR}#g' \
		${FILESDIR}/proxyper.sh > ${WRKDIR}/proxyper.sh

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi
	${CHOWN} ${PROXYUSER}:${PROXYGROUP} ${BINDIR}
	${CHMOD} 755 ${BINDIR}

	${INSTALL_PROGRAM} ${WRKSRC}/proxyper ${BINDIR}

	${INSTALL_MAN} ${WRKSRC}/ChangeLog.txt ${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/manual.html ${BINDIR}

	${INSTALL_SCRIPT} ${WRKDIR}/proxyper.sh ${PREFIX}/etc/rc.d/proxyper.sh

	${INSTALL_DATA} ${WRKSRC}/proxyper.ini ${BINDIR}/proxyper.ini.sample
.if !exists(${BINDIR}/proxyper.ini)
	${INSTALL_DATA} ${WRKSRC}/proxyper.ini ${BINDIR}/proxyper.ini
.endif

.include <bsd.port.post.mk>
