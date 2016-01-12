# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	mping
PORTVERSION=	2.01
CATEGORIES=	net ipv6
MASTER_SITES=	http://mping.uninett.no/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mping network statistics collector

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/mping \
		man/man8/mping.8.gz
PORTDOCS=	ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mping ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/mping.8 ${STAGEDIR}${MANPREFIX}/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
