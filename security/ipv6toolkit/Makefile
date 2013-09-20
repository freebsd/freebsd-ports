# $FreeBSD$

PORTNAME=	ipv6toolkit
PORTVERSION=	1.4.1
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
MAN1=		addr6.1 flow6.1 frag6.1 icmp6.1 jumbo6.1 na6.1 ni6.1 \
		ns6.1 ra6.1 rd6.1 rs6.1 scan6.1 tcp6.1
MAN5=		ipv6toolkit.conf.5

PROGDIRS=	${MAN1:S/.1//}
LIBDIRS=	libipv6

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
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
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
