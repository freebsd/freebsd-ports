# New ports collection makefile for:	milter-bogom
# Date created:			12 Feb 2005
# Whom:				Victor Balada Diaz <victor@alf.dyndns.ws>
#
# $FreeBSD$
#

PORTNAME=	milter-bogom
PORTVERSION=	1.5.1
CATEGORIES=	mail
MASTER_SITES=	http://www.usebox.net/jjm/bogom/
DISTNAME=	bogom-${PORTVERSION}

MAINTAINER=	victor@alf.dyndns.ws
COMMENT=	Simple sendmail milter to interface bogofilter

RUN_DEPENDS=	bogofilter:${PORTSDIR}/mail/bogofilter

MAN8=		bogom.8

PLIST_FILES=	sbin/bogom \
		etc/bogom.conf-example \
		etc/rc.d/milter-bogom.sh
PORTDOCS=	README CHANGELOG

post-extract:
	@${SED} -e 's/LIBS+=-lmilter -lpthread/LIBS+=-lmilter ${PTHREAD_LIBS}/'\
	-i .bak ${WRKSRC}/Makefile
	@${SED} -e 's|/etc/bogom.conf|${PREFIX}/etc/bogom.conf|' -i .bak \
	${WRKSRC}/milter.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bogom ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/bogom.8 ${PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/bogom.conf-example ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${FILESDIR}/milter-bogom.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|LOCALBASE|${PREFIX}|g' -i "" \
	${PREFIX}/etc/rc.d/milter-bogom.sh

.include <bsd.port.mk>
