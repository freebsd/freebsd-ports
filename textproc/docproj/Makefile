# New ports collection makefile for:   docproj
# Version required:    around June 1998
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	docproj
PKGNAME=	docproj-1.1
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org

RUN_DEPENDS=	instant:${PORTSDIR}/textproc/sgmlformat \
		sgmlnorm:${PORTSDIR}/textproc/sp \
		jade:${PORTSDIR}/textproc/jade \
		tidy:${PORTSDIR}/www/tidy \
		lynx:${PORTSDIR}/www/lynx \
		${PREFIX}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${PREFIX}/share/sgml/html/catalog:${PORTSDIR}/textproc/html \
		${PREFIX}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${PREFIX}/share/sgml/docbook:${PORTSDIR}/textproc/docbook \
		${PREFIX}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879

IS_INTERACTIVE= "user must set JADETEX variable to 'yes' or 'no'"

JADETEX?=

.if empty(JADETEX) && (make(build) || make(install))
.BEGIN:
	@${CAT} files/JADETEX
	@${FALSE}
.endif

.if ${JADETEX} == yes
RUN_DEPENDS+= ${PREFIX}/share/texmf/web2c/jadetex.fmt:${PORTSDIR}/print/jadetex
.endif

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
