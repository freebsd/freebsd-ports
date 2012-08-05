# New ports collection makefile for: 	thttpd
# Date created:				24 May 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	thttpd
PORTVERSION=	2.25b
PORTREVISION=	4
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/ \
		http://atreides.freenix.no/~anders/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} notes.html
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tiny/turbo/throttling HTTP server

IGNOREFILES=	notes.html

GNU_CONFIGURE=	yes

USE_RC_SUBR=	thttpd
SUB_FILES=	pkg-message thttpd.conf.sample
SUB_LIST=	WWWOWN=${WWWOWN}
PORTDOCS=	notes.html

MAN1=		makeweb.1 thttpdpasswd.1
MAN8=		thttpd.8 redirect.8 ssi.8 syslogtocern.8

.include <bsd.port.pre.mk>

post-patch:
.for f in extras/htpasswd.1 extras/htpasswd.c thttpd.8 extras/Makefile.in
	@${REINPLACE_CMD} -e \
	's|htpasswd|thttpdpasswd|g;s|\.thttpdpasswd|.htpasswd|g' ${WRKSRC}/${f}
.endfor
	${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thttpdpasswd.1
	${MV} ${WRKSRC}/extras/htpasswd.c ${WRKSRC}/extras/thttpdpasswd.c

post-configure:
	@cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/extra-patch-config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thttpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/thttpd.8 ${PREFIX}/man/man8
	@${MKDIR} ${PREFIX}/www/data ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/redirect ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/ssi ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/phf ${PREFIX}/www/cgi-bin
	${INSTALL_MAN} ${WRKSRC}/cgi-src/redirect.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/cgi-src/ssi.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/extras/makeweb ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/extras/thttpdpasswd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/extras/syslogtocern ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/extras/makeweb.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/extras/thttpdpasswd.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/extras/syslogtocern.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/notes.html ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
