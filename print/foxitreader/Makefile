# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foxitreader
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://cdn04.foxitsoftware.com/pub/foxit/%SUBDIR%/:reader,manual
MASTER_SITE_SUBDIR=	reader/desktop/linux/1.x/${PORTVERSION:R}/enu/:reader \
			manual/enu/:manual
DISTFILES=	FoxitReader-${PORTVERSION}.tar.bz2:reader
EXTRACT_ONLY=	FoxitReader-${PORTVERSION}.tar.bz2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Free PDF document viewer for desktop Linux

LICENSE_NAME=	EULA
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_TEXT=	http://www.foxitsoftware.com/pdf/desklinux/eula.htm

NO_BUILD=	yes

PLIST_SUB=	NLS="${NLS}"

USES=		gettext tar:bzip2
USE_LINUX=	yes
USE_LINUX_APPS=	cups-libs gtk2

WRKSRC=	${WRKDIR}/${PORTVERSION:R}-release

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=FoxitReader${PORTVERSION:R}ForLinux_Manual.pdf:manual
.endif
.if ${PORT_OPTIONS:MNLS}
NLS=	""
.else
NLS=	"@comment "
.endif

do-install:
	cd ${WRKSRC} && ${MKDIR} ${STAGEDIR}${DATADIR} && \
	${INSTALL_DATA} fpdfcjk.bin fum.fhd ${STAGEDIR}${DATADIR} && \
	${INSTALL_PROGRAM} FoxitReader ${STAGEDIR}${DATADIR} && \
	${LN} -s ${DATADIR}/FoxitReader ${STAGEDIR}${PREFIX}/bin/FoxitReader
.if ${PORT_OPTIONS:MNLS}
.for locale in de fr ja zh_CN zh_TW
	${INSTALL_DATA} ${WRKSRC}/po/${locale}/FoxitReader.mo ${STAGEDIR}${PREFIX}/share/locale/${locale}/LC_MESSAGES/
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/FoxitReader${PORTVERSION:R}ForLinux_Manual.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
