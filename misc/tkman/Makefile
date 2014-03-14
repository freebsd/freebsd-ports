# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkman
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk based manual browser

DEPRECATED=	Depends on expired textproc/glimpse
EXPIRATION_DATE=2014-04-10

RUN_DEPENDS=	glimpse:${PORTSDIR}/textproc/glimpse \
		rman:${PORTSDIR}/textproc/rman

USES+=		gmake tk dos2unix
MAKE_ARGS=	WISH="${WISH}" \
		texinfodir="${PREFIX}/${INFO_PATH}" \
		gzgrep="\"/usr/bin/zgrep -E\"" \
		mastermen="\"/usr/share/man ${PREFIX}/man ${LOCALBASE}/man\"" \
		masterbin="\"/usr/bin ${PREFIX}/bin ${LOCALBASE}/bin\"" \
		manformat="{groff -Tlatin1 -te -mandoc}" \
		manprint="{groff -mandoc -Tps -te -l}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/wish|${WISH}|' \
		${WRKSRC}/contrib/tkmanclient

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/retkman ${STAGEDIR}${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.html ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/tkmanclient ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${FILESDIR}/310.index_manpages ${STAGEDIR}${PREFIX}/etc/periodic/weekly

.include <bsd.port.mk>
