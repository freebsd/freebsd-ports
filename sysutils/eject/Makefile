# Created by: shige
# $FreeBSD$

PORTNAME=	eject
PORTVERSION=	1.5
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/OD/ \
		ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/OD/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/OD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for ejecting media from CD or optical disk drive

LICENSE=	BSD2CLAUSE

USES=		uidfix
PLIST_FILES=	sbin/eject \
		man/man1/eject.1.gz
PORTDOCS=	README README-J
MAKE_ARGS=	BINOWN=${BINOWN}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,4555,555,' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
