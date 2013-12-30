# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	fl0p
PORTVERSION=	0.0.2.b
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.coredump.cx/soft/
DISTNAME=	fl0p-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passive L7 flow fingerprinting tool

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	ChangeLog CREDITS README TODO
PLIST_FILES=	bin/fl0p %%DATADIR%%/fl0p.fp
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|"/etc/fl0p"|"${DATADIR}"|' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e \
		's|^GMAKE_OK|#GMAKE_OK|' ${WRKSRC}/Build
	@${REINPLACE_CMD} -e \
		'/^CC/s|\([[:blank:]]\)=|\1?=| ; \
		 /^CFLAGS/s|\([[:blank:]]\)=|\1+=| ; \
		 s|-g -ggdb|| ; \
		 s|-I.*|$$(CPPFLAGS)| ; \
		 /^all:/s|strip||' ${WRKSRC}/mk/Linux

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} fl0p ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} fl0p.fp ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
