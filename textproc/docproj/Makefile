# New ports collection makefile for:   docproj
# Version required:    around June 1998
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $Id: Makefile,v 1.7 1999/01/20 22:19:42 nik Exp $
#

DISTNAME=	docproj
PKGNAME=	docproj-1.0
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org

RUN_DEPENDS=	instant:${PORTSDIR}/textproc/sgmlformat \
		${PREFIX}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		tidy:${PORTSDIR}/www/tidy \
		${PREFIX}/share/sgml/html/catalog:${PORTSDIR}/textproc/html

IS_INTERACTIVE= "user must set JADETEX variable to 'yes' or 'no'"

JADETEX?=

.if empty(JADETEX) && (make(fetch) || make(build) || make(install))
.BEGIN:
	@${CAT} pkg/JADETEX
	@${FALSE}
.endif

.if ${JADETEX} == yes
RUN_DEPENDS+= ${PREFIX}/share/texmf/web2c/jadetex.fmt:${PORTSDIR}/print/jadetex
.endif

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
