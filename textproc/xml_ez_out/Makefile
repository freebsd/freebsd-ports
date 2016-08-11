# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xml_ez_out
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.mckae.com/xml_ezout/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Library for emitting XML from Ada programs

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

USES=		ada dos2unix tar:tgz
WRKSRC=		${WRKDIR}/xml_ez_out
BUILD_WRKSRC=	${WRKSRC}/mckae
PORTDOCS=	README
PORTEXAMPLES=	example.gpr tmeztf.adb runme.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-extract:
	${CP} ${FILESDIR}/xezo_bld.gpr ${WRKSRC}
	${SED} -e "s,@PREFIX@,${LOCALBASE},g" ${FILESDIR}/runme.sh.in \
		> ${WRKSRC}/runme.sh

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -Pxezo_bld)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/xml_ez_out \
		${STAGEDIR}${PREFIX}/include/xml_ez_out
	${INSTALL_DATA} ${FILESDIR}/xml_ez_out.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${BUILD_WRKSRC}/mckae* \
		${STAGEDIR}${PREFIX}/include/xml_ez_out
	${INSTALL_DATA} ${WRKSRC}/lib/*  \
		${STAGEDIR}${PREFIX}/lib/xml_ez_out
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/runme.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/tmeztf.adb \
		${FILESDIR}/example.gpr ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
