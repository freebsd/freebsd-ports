# $FreeBSD$

PORTNAME=	ua
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.shatow.net/freebsd/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finds sets of identical files

LICENSE=	GPLv2

DEPRECATED=	No upstream, unmaintained
EXPIRATION_DATE=2014-07-01

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/kua bin/ua \
		man/man1/kua.1.gz man/man1/ua.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
