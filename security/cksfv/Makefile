# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	cksfv
PORTVERSION=	1.3.14
CATEGORIES=	security
MASTER_SITES=	http://zakalwe.fi/~shd/foss/cksfv/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create or manipulate Simple File Verification (SFV) checksum files

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --prefix=${PREFIX}

PLIST_FILES=	bin/cksfv man/man1/cksfv.1.gz
PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)=|\1?=|' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
