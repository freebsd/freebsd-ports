# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Version required:	1.40
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $Id: Makefile,v 1.16 1999/04/04 16:37:29 nik Exp $
#

DISTNAME=	db140
PKGNAME=	dsssl-docbook-modular-1.40
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
EXTRACT_SUFX=	.zip
DISTFILES=	db140.zip db140d.zip

MAINTAINER=	kuriyama@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook-300
RUN_DEPENDS=	${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook-300

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -q -L
EXTRACT_AFTER_ARGS=	# empty
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/docbook

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

do-build:
	@${RM} -Rf ${WRKSRC}/docsrc

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
