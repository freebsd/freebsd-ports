# New ports collection makefile for:   webreport
# Date created:       06 Feb 2004
# Whom:                ismail@enderunix.org
#
# $FreeBSD$
#

PORTNAME=	webreport
PORTVERSION=	1.5
CATEGORIES=	www
MASTER_SITES=	http://www.inter7.com/webreport/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	WebReport is a web log statistics program  for web hosting sites

PORTDOCS=	INSTALL
PLIST_FILES=	bin/webreport etc/webreport.conf-dist

post-patch:
	@${REINPLACE_CMD} -e 's,ulong,unsigned long,;s,/etc/,${PREFIX}/etc/,' ${WRKSRC}/webreport.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webreport ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/webreport.conf ${PREFIX}/etc/webreport.conf-dist

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
