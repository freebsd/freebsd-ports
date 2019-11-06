# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foxitreader
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://cdn04.foxitsoftware.com/pub/foxit/reader/desktop/linux/1.x/${PORTVERSION:R}/enu/:reader
DISTFILES=	FoxitReader-${PORTVERSION}.tar.bz2:reader
EXTRACT_ONLY=	FoxitReader-${PORTVERSION}.tar.bz2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Free PDF document viewer for desktop Linux

BROKEN=		unfetchable

LICENSE=	EULA
LICENSE_NAME=	End-User License Agreement
LICENSE_TEXT=	http://www.foxitsoftware.com/pdf/desklinux/eula.htm
LICENSE_PERMS=	auto-accept

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

USES=		gettext linux tar:bzip2
USE_LINUX=	avahi-libs cups-libs dbuslibs gtk2 nss

WRKSRC=		${WRKDIR}/${PORTVERSION:R}-release

DOCS_MASTER_SITES=	http://cdn04.foxitsoftware.com/pub/foxit/manual/enu/:manual
DOCS_DISTFILES=		FoxitReader${PORTVERSION:R}ForLinux_Manual.pdf:manual

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} fpdfcjk.bin fum.fhd ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/FoxitReader ${STAGEDIR}${DATADIR}
	${LN} -s ${DATADIR}/FoxitReader ${STAGEDIR}${PREFIX}/bin/FoxitReader

do-install-NLS-on:
.for locale in de fr ja zh_CN zh_TW
	${INSTALL_DATA} ${WRKSRC}/po/${locale}/FoxitReader.mo ${STAGEDIR}${PREFIX}/share/locale/${locale}/LC_MESSAGES/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/FoxitReader${PORTVERSION:R}ForLinux_Manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
