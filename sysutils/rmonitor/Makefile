# Created by: Konrad Heuer
# $FreeBSD$

PORTNAME=	rmonitor
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://gwdu111.gwdg.de/pub/FreeBSD/misc/ \
		ftp://gwdu112.gwdg.de/pub/FreeBSD/misc/

MAINTAINER=	kheuer@gwdg.de
COMMENT=	Remote system monitoring utility

LICENSE=	BSD4CLAUSE

CFLAGS+=	-w

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-utmpx
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rmonitor ${STAGEDIR}${PREFIX}/bin/rmonitor
	${INSTALL_MAN} ${WRKSRC}/man/rmonitor.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/rmonitor.1.gz
	${INSTALL_SCRIPT} ${WRKSRC}/etc/rmonitor.sh ${STAGEDIR}${PREFIX}/etc/rc.d/rmonitor.sh

.include <bsd.port.post.mk>
