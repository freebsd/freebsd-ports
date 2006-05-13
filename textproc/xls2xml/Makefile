# New ports collection makefile for:	xls2xml
# Date created:				4 November 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xls2xml
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://arturo.directmail.org/filters/archive/
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for converting MS Excel files to XML

LIB_DEPENDS=	cole.2:${PORTSDIR}/textproc/cole \
		xml.5:${PORTSDIR}/textproc/libxml

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lcole"

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
