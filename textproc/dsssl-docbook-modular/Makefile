# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Version required:	1.30
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $Id: Makefile,v 1.12 1998/11/09 10:03:59 kuriyama Exp $
#

DISTNAME=	db130
PKGNAME=	dsssl-docbook-modular-1.30
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
EXTRACT_SUFX=	.zip

PATCH_SITES=	http://www.freebsd.org/~kuriyama/distfiles/
PATCHFILES=	db130jpja-981223.diff.gz
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook
RUN_DEPENDS=	${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -q -L
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/docbook

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@find ${WRKDIR} -name '*~' -exec ${RM} {} \;
	@find ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include <bsd.port.mk>
