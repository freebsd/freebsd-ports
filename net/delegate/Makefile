# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	delegate
PORTVERSION=	9.9.10
CATEGORIES=	net www
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	General purpose TCP/IP proxy system

USES=		gmake
SUB_FILES=	pkg-message

PLIST_FILES=	sbin/delegated etc/rc.d/delegated.sh-dist
PORTDOCS=	CHANGES COPYRIGHT DG9note.html HowToDG.html IPv6NOTE.txt \
		Manual.htm jpconv.htm tutor-en.htm tutor-jp.htm

post-extract:
	@${LN} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/DG9note.html \
		${WRKSRC}/IPv6NOTE.txt ${WRKSRC}/doc

post-patch:
# Prevent "filesystem was touched prior to 'make install' phase" warning;
# allow unattended (non-interactive) builds
	@${REINPLACE_CMD} -e 's,"$$(XDG)",& DGROOT=${WRKDIR},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E '/ADMIN/s,undef,admin@example.com, ; \
		s,-F(esign|ver),& DGROOT=${WRKDIR},' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/delegated.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/delegated.sh-dist
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
