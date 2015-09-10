# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/print/foxitreader/Makefile 349771 2014-03-31 16:30:11Z nivit $

PORTNAME=	foxitreader
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://cdn04.foxitsoftware.com/pub/foxit/reader/desktop/linux/1.x/${PORTVERSION:R}/enu/:reader
			
DISTFILES=	FoxitReader-${PORTVERSION}.tar.bz2:reader
EXTRACT_ONLY=	FoxitReader-${PORTVERSION}.tar.bz2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Free PDF document viewer for desktop Linux

LICENSE=	EULA
LICENSE_NAME=	End-User License Agreement
LICENSE_PERMS=	auto-accept
LICENSE_TEXT=	http://www.foxitsoftware.com/pdf/desklinux/eula.htm

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

USES=	gettext tar:bzip2
USE_LINUX=	yes
USE_LINUX_APPS=	avahi-libs cups-libs dbuslibs gtk2 nss

WRKSRC=	${WRKDIR}/${PORTVERSION:R}-release

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MASTER_SITES+=	http://cdn04.foxitsoftware.com/pub/foxit/manual/enu/:manual
DISTFILES+=	FoxitReader${PORTVERSION:R}ForLinux_Manual.pdf:manual
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} fpdfcjk.bin fum.fhd ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/FoxitReader ${STAGEDIR}${DATADIR}
	${LN} -s ${DATADIR}/FoxitReader ${STAGEDIR}${PREFIX}/bin/FoxitReader
.if ${PORT_OPTIONS:MNLS}
.for locale in de fr ja zh_CN zh_TW
	${INSTALL_DATA} ${WRKSRC}/po/${locale}/FoxitReader.mo ${STAGEDIR}${PREFIX}/share/locale/${locale}/LC_MESSAGES/
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/FoxitReader${PORTVERSION:R}ForLinux_Manual.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
