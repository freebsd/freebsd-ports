# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Version required:	1.33
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $Id: Makefile,v 1.14 1999/01/16 07:44:13 kuriyama Exp $
#

DISTNAME=	db133
PKGNAME=	dsssl-docbook-modular-1.33
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
EXTRACT_SUFX=	.zip

PATCH_SITES=	http://www.freebsd.org/~kuriyama/distfiles/
PATCHFILES=	db133ja-990116.diff.gz
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook
RUN_DEPENDS=	${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -q -L
EXTRACT_AFTER_ARGS=	# empty
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
