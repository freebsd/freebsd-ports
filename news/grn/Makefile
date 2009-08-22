# New ports collection makefile for:	grm
# Date created:				20 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grn
PORTVERSION=	0.0.28
PORTREVISION=	6
CATEGORIES=	news gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/pre-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A NNTP client for Gnome

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ENV=	glibpath="${GLIB_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure ${WRKSRC}/libmutt/configure

.include <bsd.port.mk>
