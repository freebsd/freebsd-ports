# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Version required:	1.08
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $Id: Makefile,v 1.2 1998/06/19 15:25:16 kuriyama Exp $
#

DISTNAME=	db108
PKGNAME=	dsssl-docbook-modular-1.08
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
EXTRACT_SUFX=	.zip

MAINTAINER=	kuriyama@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook
RUN_DEPENDS=	${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -q -L
NO_MTREE=	yes
NO_BUILD=	yes

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@find ${WRKDIR} -name '*~' -exec rm {} \;

do-install:
	@${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include <bsd.port.mk>
