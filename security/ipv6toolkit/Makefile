# $FreeBSD$

PORTNAME=	ipv6toolkit
PORTVERSION=	1.5.2
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.si6networks.com/tools/ipv6toolkit/
DISTNAME=	ipv6toolkit-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Set of IPv6 security assessment tools

LICENSE=	GPLv3

MAKE_ENV=	DATADIR=${DATADIR} WRKSRC=${WRKSRC}
SUB_FILES=	BSDMakefile Makefile Makefile.lib
MAKEFILE=	BSDMakefile
PORTDOCS=	README.TXT CHANGES.TXT CONTRIB.TXT

PROGDIRS=	addr6 flow6 frag6 icmp6 jumbo6 na6 ni6 ns6 ra6 rd6 rs6 \
		scan6 tcp6
LIBDIRS=	libipv6

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@cd ${WRKSRC} && ${MKDIR} ${PROGDIRS} ${LIBDIRS}

post-patch: apply-slist
	${INSTALL_DATA} ${WRKDIR}/BSDMakefile ${WRKSRC}
	for D in ${PROGDIRS}; do \
		${INSTALL_DATA} ${WRKDIR}/Makefile ${WRKSRC}/$$D; \
	done
	for D in ${LIBDIRS}; do \
		${INSTALL_DATA} ${WRKDIR}/Makefile.lib ${WRKSRC}/$$D/Makefile; \
	done

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
