# New ports collection makefile for:   man2web
# Date created:                2003-04-19
# Whom:                        Christian Weisgerber <naddy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	man2web
PORTVERSION=	0.88
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Convert man pages to HTML

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/${CGIDIR}" \
		--sysconfdir="${PREFIX}/etc" \
		--with-manpath=/usr/share/man:${LOCALBASE}/man \
		--with-distro=freebsd --enable-lynx
MAKE_JOBS_SAFE=	yes

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
