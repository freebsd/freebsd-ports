# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dsssl-docbook-modular
PORTVERSION=	1.64
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
DISTNAME=	db${PORTVERSION:S/.//g}
DISTFILES=	${DISTNAME}.zip ${DISTNAME}d.zip

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook-300
RUN_DEPENDS=	${PREFIX}/share/sgml/docbook/3.0/catalog:${PORTSDIR}/textproc/docbook-300

USE_ZIP=	YES
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/docbook
EXTRACT_BEFORE_ARGS=	-a -q

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

do-build:
	@${RM} -Rf ${WRKSRC}/docsrc

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@find ${WRKDIR} -name '*~' -exec ${RM} {} \;
	@find ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include <bsd.port.mk>
