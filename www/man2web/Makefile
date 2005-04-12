# New ports collection makefile for:   man2web
# Date created:                2003-04-19
# Whom:                        Christian Weisgerber <naddy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	man2web
PORTVERSION=	0.88
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Convert man pages to HTML

GNU_CONFIGURE=	yes
CONFIGURE_TARGET= --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--bindir="${PREFIX}/${CGIDIR}" \
		--sysconfdir="${PREFIX}/etc" \
		--with-manpath=/usr/share/man:${X11BASE}/man:${LOCALBASE}/man \
		--with-distro=freebsd --enable-lynx

PLIST_SUB=	CGIDIR="${CGIDIR}"
CGIDIR=	www/cgi-bin

MAN1=	man2web.1
MAN5=	man2web.conf.5

post-extract:
	${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/src/section_h/

# default Apache configuration disallows symlinks in cgi-bin
post-install:
	${LN} -sf ${PREFIX}/${CGIDIR}/man2web ${PREFIX}/bin/man2web

.include <bsd.port.mk>
