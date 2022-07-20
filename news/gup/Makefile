PORTNAME=	gup
PORTVERSION=	0.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.isc.org/isc/inn/unoff-contrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows remote sites to change their newsgroup subscriptions

WRKSRC=		${WRKDIR}/gup

PLIST_FILES=	libexec/gup man/man1/gup.1.gz

do-configure:
	@${CP} ${FILESDIR}/freebsd ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gup ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/gup.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
