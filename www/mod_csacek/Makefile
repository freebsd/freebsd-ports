# New ports collection makefile for:	mod_csacek Apache module
# Date created:				22 Feb 2001
# Whom:					Milan Salajka <ms@vol.cz>
#
# $FreeBSD$
#

PORTNAME=	mod_csacek
PORTVERSION=	2.1.5
CATEGORIES=	www
MASTER_SITES=	http://www.csacek.cz/distrib/
DISTNAME=	${PORTNAME:S/mod_//g}-${PORTVERSION}

MAINTAINER=	ms@vol.cz

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-target=Apache \
		--disable-report \
		--with-templatedir=${PREFIX}/www/data \
		--disable-compression

do-install:
	${APXS} -i -A -n csacek ${WRKSRC}/mod_csacek.so

post-install:

	${INSTALL_DATA} ${WRKSRC}/templates/whichcode_template.html ${PREFIX}/www/data

	${MKDIR} ${PREFIX}/share/doc/mod_csacek
	${MKDIR} ${PREFIX}/share/doc/mod_csacek/img
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/doc/img/*.gif ${PREFIX}/share/doc/${PORTNAME}/img

	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
