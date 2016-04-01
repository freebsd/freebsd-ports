# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	http-analyze
PORTVERSION=	2.4.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.rent-a-guru.de/pub/
DIST_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:R}-src

PATCH_SITES=	http://http-analyze.org/
PATCHFILES=	patch04.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Log-Analyzer for web servers

LIB_DEPENDS=	libgd.so:graphics/gd

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

MAKE_ARGS=	HA_BINDIR="${PREFIX}/bin" HA_LIBDIR="${DATADIR}" \
		REQINCS="${CPPFLAGS}" REQLIBS="${LDFLAGS}" \
		DEFINES="-DBSD -Dunix" OPTIM="${CFLAGS}" \
		CC="${CC}"
ALL_TARGET=	${PORTNAME}

CPPFLAGS+=	$$(gdlib-config --includes)
LDFLAGS+=	$$(gdlib-config --ldflags) $$(gdlib-config --libs)

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} http-analyze \
		${STAGEDIR}${PREFIX}/bin/http-analyze)
	(cd ${WRKSRC}/man && ${INSTALL_MAN} http-analyze.man \
		${STAGEDIR}${MANPREFIX}/man/man1/http-analyze.1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/files && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in http-analyze.pdf http-analyze.ps.gz
	(cd ${WRKSRC}/man && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in contrib tools
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${EXAMPLESDIR})
.endfor
.endif

.include <bsd.port.mk>
