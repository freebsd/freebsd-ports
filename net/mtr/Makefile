# New ports collection makefile for:   mtr
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	mtr
PORTVERSION=	0.42
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	billf@FreeBSD.org

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GTK=	yes

MAN8=	mtr.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
PATCHFILES=	mtr-042-v6-20000719.diff.gz
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCH_DIST_STRIP=	-p1

CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if defined(HAVE_GTK)
USE_XLIB=	yes
USE_GTK=	yes
.else
CONFIGURE_ARGS+=--with-gtk-prefix=/nopath
.endif

do-install:
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8

post-install:
	@${ECHO} ""
	@${ECHO} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO} ""
	@${ECHO} "Please read about potential security issues"
	@${ECHO} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO} ""

.include <bsd.port.post.mk>
