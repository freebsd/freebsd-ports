# New ports collection makefile for:	xxxterm
# Date created:				2011.01.15
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	xxxterm
PORTVERSION=	1.97
CATEGORIES=	www
MASTER_SITES=	http://opensource.conformal.com/snapshots/xxxterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Minimalists vi-like web browser based on webkit and GTK+

LIB_DEPENDS=	webkit-1.0:${PORTSDIR}/www/webkit-gtk2 \
		utils.1:${PORTSDIR}/lang/libutils \
		soup-2.4:${PORTSDIR}/devel/libsoup

USE_GNOME=	gtk20 pkgconfig

PLIST_FILES=	bin/xxxterm
MAN1=		xxxterm.1
PORTEXAMPLES=	favorites xxxterm.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xxxterm ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xxxterm.1 ${PREFIX}/man/man1/
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/favorites ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/xxxterm.conf ${EXAMPLESDIR}/
.endif

# vim: set ts=8 sw=8:
.include <bsd.port.mk>
