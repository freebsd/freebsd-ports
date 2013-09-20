# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcmplex-panteltje
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://panteltje.com/panteltje/dvd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Re-write of the A/V multiplexer from the transcode distribution

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	a.out

PORTDOCS=	CHANGES COPYRIGHT README
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
