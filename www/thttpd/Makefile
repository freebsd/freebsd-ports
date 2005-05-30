# New ports collection makefile for: 	thttpd
# Date created:		24 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	thttpd
PORTVERSION=	2.25b
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/ \
		http://atreides.freenix.no/~anders/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} notes.html
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Tiny/turbo/throttling HTTP server

IGNOREFILES=	notes.html

GNU_CONFIGURE=	yes

USE_RC_SUBR=	thttpd.sh
SUB_FILES=	pkg-message thttpd.conf.sample
SUB_LIST=	WWWOWN=${WWWOWN}
PORTDOCS=	notes.html

MAN1=		makeweb.1 htpasswd.1
MAN8=		thttpd.8 redirect.8 ssi.8 syslogtocern.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502101
post-configure:
	@cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/extra-patch-config.h
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thttpd ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/thttpd.8 ${PREFIX}/man/man8
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/www
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/www/data
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/www/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/redirect ${PREFIX}/www/cgi-bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/ssi ${PREFIX}/www/cgi-bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/phf ${PREFIX}/www/cgi-bin/
	@${INSTALL_MAN} ${WRKSRC}/cgi-src/redirect.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/cgi-src/ssi.8 ${PREFIX}/man/man8
	@${INSTALL_PROGRAM} ${WRKSRC}/extras/makeweb ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/extras/htpasswd ${PREFIX}/bin/
	@${INSTALL_SCRIPT} ${WRKSRC}/extras/syslogtocern ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/extras/makeweb.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/extras/htpasswd.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/extras/syslogtocern.8 ${PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKDIR}/thttpd.conf.sample ${PREFIX}/etc/thttpd.conf.sample
	@${INSTALL_SCRIPT} ${WRKDIR}/thttpd.sh ${PREFIX}/etc/rc.d/thttpd.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/notes.html ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
