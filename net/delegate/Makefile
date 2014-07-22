# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	delegate
PORTVERSION=	9.9.10
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	General purpose TCP/IP proxy system

USES=		gmake
SUB_FILES=	pkg-message

ADMIN?=		admin@example.com

PLIST_FILES=	sbin/delegated etc/rc.d/delegated.sh-dist
PORTDOCS=	CHANGES COPYRIGHT DG9note.html HowToDG.html IPv6NOTE.txt \
		Manual.htm jpconv.htm tutor-en.htm tutor-jp.htm

# Strip breaks binary checksumming
STRIP=

post-extract:
	@${LN} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/DG9note.html \
		${WRKSRC}/IPv6NOTE.txt ${WRKSRC}/doc

post-patch:
	@${REINPLACE_CMD} -E "/ADMIN/s,undef,${ADMIN}," ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/delegated.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/delegated.sh-dist
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
