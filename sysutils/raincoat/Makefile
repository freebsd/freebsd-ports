# New ports collection makefile for:	raincoat
# Date created:				24 July 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=		raincoat
PORTVERSION=		0.11
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xbox-linux
EXTRACT_SUFX=		.tbz2

MAINTAINER=		ed@fxq.nl
COMMENT=		BIOS flash utility for the Microsoft Xbox

# Xbox is i386
ONLY_FOR_ARCHS=		i386

USE_BZIP2=		yes

PORTDOCS=		README

post-patch:
.for f in docs/README src/${PORTNAME}.c
	@${REINPLACE_CMD} -e 's|/etc/raincoat\.conf|${PREFIX}&|g' \
		${WRKSRC}/${f}
.endfor

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/src/${PORTNAME}.c ${WRKSRC}/src/BootFlash.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.default
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${PREFIX}/etc
.endif

.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Doesn't build on < 5.x"
.endif

.include <bsd.port.post.mk>
