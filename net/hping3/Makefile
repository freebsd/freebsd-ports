PORTNAME=	hping3
PORTVERSION=	20051105
CATEGORIES=	net security
MASTER_SITES=	http://www.hping.org/ \
		http://200ok.org/distfiles/hping/

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Network auditing tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=		yes
TCL_CONFIGURE_OFF=	--no-tcl

PLIST_FILES=	sbin/${PORTNAME}

PORTDOCS_en=	APD.txt API.txt AS-BACKDOOR HPING2-HOWTO.txt HPING2-IS-OPEN \
		HPING3.txt MORE-FUN-WITH-IPID SPOOFED_SCAN.txt hping2rc.example
PORTDOCS_fr=	AS-BACKDOOR hping2-fr.8 hping2-fr.8.txt HPING2-HOWTO.txt \
		HPING2-IS-OPEN INSTALL MORE-FUN-WITH-IPID NEWS SPOOFED_SCAN.txt
PORTDOCS=	${PORTDOCS_en} ${PORTDOCS_fr:S/^/french\//}

OPTIONS_DEFINE=		DOCS MAN TCL
OPTIONS_DEFAULT=	DOCS MAN
TCL_USES=		tcl

MAN_DESC=		Install manual page

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAN}
PLIST_FILES+=	man/man8/${PORTNAME}.8.gz
.endif

.if ${PORT_OPTIONS:MTCL}
LDFLAGS+=	-L${PREFIX}/lib
.endif

pre-configure-TCL-on:
	${REINPLACE_CMD} 's,"8.4",${TCL_VER},' ${WRKSRC}/configure
.if ${LOCALBASE} != /usr/local
	${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},' ${WRKSRC}/configure
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/french
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS_en} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/french && ${INSTALL_DATA} ${PORTDOCS_fr} ${STAGEDIR}${DOCSDIR}/french

do-install-MAN-on:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.8 \
		${STAGEDIR}${MANPREFIX}/man/man8/${PORTNAME}.8

.include <bsd.port.mk>
