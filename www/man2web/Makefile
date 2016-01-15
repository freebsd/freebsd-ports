# $FreeBSD$

PORTNAME=	man2web
PORTVERSION=	0.88
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert man pages to HTML

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/GPL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/${CGIDIR}" \
		--sysconfdir="${PREFIX}/etc" \
		--with-manpath=/usr/share/man:${LOCALBASE}/man \
		--with-distro=freebsd --enable-lynx

CGIDIR=		www/cgi-bin
PLIST_SUB=	CGIDIR="${CGIDIR}"

post-extract:
	${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/src/section_h/

# default Apache configuration disallows symlinks in cgi-bin
post-install:
	${LN} -sf ${PREFIX}/${CGIDIR}/man2web ${STAGEDIR}${PREFIX}/bin/man2web

.include <bsd.port.mk>
