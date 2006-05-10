# New ports collection makefile for:	tkman
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkman
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	misc tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	andrew.nau.ua@gmail.com
COMMENT=	A Tcl/Tk based manual browser

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

USE_GMAKE=	yes
MAKE_ARGS=	WISH="${PREFIX}/bin/wish8.4" \
		texinfodir="${PREFIX}/info" \
		gzgrep="\"/usr/bin/zgrep -E\"" \
		mastermen="\"/usr/share/man ${PREFIX}/man ${X11BASE}/man\"" \
		masterbin="\"/usr/bin ${PREFIX}/bin ${X11BASE}/bin\"" \
		manformat="{groff -Tlatin1 -te -mandoc}" \
		manprint="{groff -mandoc -Tps -te -l}"

post-patch:
	@${REINPLACE_CMD} -e "s;/usr/local/bin/wish;${PREFIX}/bin/wish8.4;" \
		${WRKSRC}/contrib/tkmanclient

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkman ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/retkman ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.html ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/tkmanclient ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${FILESDIR}/310.index_manpages ${PREFIX}/etc/periodic/weekly

.include <bsd.port.mk>
