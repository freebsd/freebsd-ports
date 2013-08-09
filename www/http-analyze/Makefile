# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	http-analyze
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.rent-a-guru.de/pub/
DIST_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:R}-src

PATCH_SITES=	http://http-analyze.org/
PATCHFILES=	patch04.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Log-Analyzer for web servers

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

MAKE_ARGS=	HA_BINDIR="${PREFIX}/bin" HA_LIBDIR="${DATADIR}" \
		REQINCS="${CPPFLAGS}" REQLIBS="${LDFLAGS}" \
		DEFINES="-DBSD -Dunix" OPTIM="${CFLAGS}" \
		CC="${CC}"
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	$$(gdlib-config --includes)
LDFLAGS+=	$$(gdlib-config --ldflags) $$(gdlib-config --libs)

MAN1=		http-analyze.1

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_DATA} http-analyze \
		${PREFIX}/bin/http-analyze)
	(cd ${WRKSRC}/man && ${INSTALL_MAN} http-analyze.man \
		${MANPREFIX}/man/man1/http-analyze.1)
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/files && ${COPYTREE_SHARE} . ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in http-analyze.pdf http-analyze.ps.gz
	(cd ${WRKSRC}/man && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for i in contrib tools
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${EXAMPLESDIR})
.endfor
.endif

.include <bsd.port.mk>
