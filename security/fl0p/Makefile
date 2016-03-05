# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	fl0p
PORTVERSION=	0.0.2.b
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.coredump.cx/soft/
DISTNAME=	fl0p-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passive L7 flow fingerprinting tool

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	ChangeLog CREDITS README TODO
PLIST_FILES=	bin/fl0p %%DATADIR%%/fl0p.fp

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|"/etc/fl0p"|"${DATADIR}"|' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e \
		's|^MAKE_CMD_OK|#MAKE_CMD_OK|' ${WRKSRC}/Build
	@${REINPLACE_CMD} -e \
		'/^CC/s|\([[:blank:]]\)=|\1?=| ; \
		 /^CFLAGS/s|\([[:blank:]]\)=|\1+=| ; \
		 s|-g -ggdb|| ; \
		 s|-I.*|$$(CPPFLAGS)| ; \
		 /^all:/s|strip||' ${WRKSRC}/mk/Linux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fl0p ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fl0p.fp ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
