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
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --prefix=${PREFIX}

MAN1=		cksfv.1
PLIST_FILES=	bin/cksfv
PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)=|\1?=|' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
