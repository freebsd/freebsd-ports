# New ports collection makefile for:	daemontools
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	daemontools
PORTVERSION=	0.76
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://cr.yp.to/daemontools/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

.if !defined(WITHOUT_MAN)
MANDATE=	-20010714
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:1
DISTFILES+=	${DISTNAME}-man${MANDATE}.tar.gz:1

MAN8=		envdir.8 envuidgid.8 fghack.8 multilog.8 pgrphack.8 \
		readproctitle.8 setlock.8 setuidgid.8 softlimit.8 \
		supervise.8 svc.8 svok.8 svscan.8 svscanboot.8 svstat.8 \
		tai64n.8 tai64nlocal.8
MANCOMPRESSED=	no
.endif

MAINTAINER=	roam@FreeBSD.org

WRKSRC=		${WRKDIR}/admin/${DISTNAME}/src
NO_PACKAGE=	"Unsure of djb\'s license"

ALL_TARGET=	it
INSTALL_TARGET=	setup check

SAMPLERC=	svscan.sh.sample
SERVICEDIR?=	/var/service/

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} ${STRIP}" > ${WRKSRC}/conf-ld

post-build:
	@${SED} "s!/usr/local/!${PREFIX}/!;s!/var/service!${SERVICEDIR}!g" \
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}

do-install:
	(while read cmd; do \
		if file ${WRKSRC}/$$cmd | ${GREP} -q "shell script"; then \
			${INSTALL_SCRIPT} ${WRKSRC}/$$cmd ${PREFIX}/bin; \
		else \
			${INSTALL_PROGRAM} ${WRKSRC}/$$cmd ${PREFIX}/bin; \
		fi \
	done) < ${WRKSRC}/../package/commands

post-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${SAMPLERC} \
		${PREFIX}/share/examples/${PORTNAME}
.if !defined(WITHOUT_MAN)
	@${INSTALL_MAN} ${WRKDIR}/daemontools-man/*.8 ${PREFIX}/man/man8/
.endif

.include <bsd.port.mk>
