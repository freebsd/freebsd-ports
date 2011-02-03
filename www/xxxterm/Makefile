# New ports collection makefile for:	xxxterm
# Date created:				2011.01.15
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	xxxterm
PORTVERSION=	1.275
CATEGORIES=	www
MASTER_SITES=	http://opensource.conformal.com/snapshots/xxxterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Minimalists vi-like web browser based on webkit and GTK+

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls \
		soup-2.4:${PORTSDIR}/devel/libsoup \
	   	webkit-1.0:${PORTSDIR}/www/webkit-gtk2

USE_GNOME=	gtk20 pkgconfig
USE_PERL5_BUILD=YES

PLIST_FILES=	bin/xxxterm
MAN1=		xxxterm.1
PORTEXAMPLES=	favorites xxxterm.conf
PLIST_DIRS+=	share/xxxterm

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800041
BROKEN=		does not build due to missing arc4random_buf in libc
.endif

ICONS= 16 32 48 64 128
.for i in ${ICONS}
PLIST_FILES+= share/xxxterm/xxxtermicon${i}.png
.endfor

do-build:
	(cd ${WRKSRC}/freebsd && make)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd/xxxterm ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xxxterm.1 ${PREFIX}/man/man1/
	${MKDIR} ${PREFIX}/share/${PORTNAME}
.for i in ${ICONS}
	${INSTALL_DATA}  ${WRKSRC}/xxxtermicon${i}.png ${PREFIX}/share/xxxterm/
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/favorites ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/xxxterm.conf ${EXAMPLESDIR}/
.endif

# vim: set ts=8 sw=8:
.include <bsd.port.post.mk>
