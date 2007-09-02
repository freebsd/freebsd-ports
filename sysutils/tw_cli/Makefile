# New ports collection makefile for:	tw_cli
# Date created:				02/12/2005
# Whom:					Dmitry Frolov <frolov@riss-telecom.ru>
#
# $FreeBSD$
#

PORTNAME=	tw_cli
PORTVERSION=	9.4.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://3ware.com/download/Escalade9650SE-Series/${PORTVERSION}/
DISTNAME=	${PORTNAME}-freebsd-${DIST_ARCH}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	frolov@riss-telecom.ru
COMMENT=	3ware storage controllers management CLI

USE_PERL5_RUN=	yes
RESTRICTED=	Redistribution is not allowed
# i386 binary should work on ia64, but not tested
ONLY_FOR_ARCHS=	i386 amd64 ia64

WRKSRC=	${WRKDIR}
NO_BUILD=	yes
STRIP=		# empty
SUB_FILES+=	407.status-3ware-raid
PLIST_FILES=	sbin/tw_cli sbin/tw_sched \
	etc/periodic/daily/407.status-3ware-raid
PLIST_DIRS=	etc/periodic/daily etc/periodic
PORTDOCS=	tw_cli.8.html tw_sched.8.html
MAN8+=		tw_cli.8 tw_sched.8

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
DIST_ARCH=	x86_64
.else
DIST_ARCH=	x86
.endif

do-configure:
	${REINPLACE_CMD} 's!/usr/bin/perl!${PERL}!g' ${WRKSRC}/tw_sched

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tw_cli ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/tw_sched ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/tw_cli.8.nroff ${MANPREFIX}/man/man8/tw_cli.8
	${INSTALL_MAN} ${WRKSRC}/tw_sched.8.nroff ${MANPREFIX}/man/man8/tw_sched.8
	@${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/407.status-3ware-raid \
		${PREFIX}/etc/periodic/daily/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tw_cli.8.html ${WRKSRC}/tw_sched.8.html \
		${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
