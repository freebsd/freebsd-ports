# Created by: Edson Brandi <ebrandi@fugspbr.org>
# $FreeBSD$

PORTNAME=	wipe
PORTVERSION=	2.3.1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	File and block device wiping utility

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wipe

MAN1=		wipe.1
PORTDOCS=	CHANGES INSTALL LICENSE README TESTING TODO copyright

post-patch:
	@${REINPLACE_CMD} -e 's|@CFLAGS@|${CFLAGS}|' ${WRKSRC}/Makefile.in

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	for i in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
