# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dsssl-docbook-modular
PORTVERSION=	1.78
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docbook
DISTNAME=	docbook-dsssl-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} docbook-dsssl-doc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	DSSSL stylesheets for the DocBook DTD by Norman Walsh

NO_MTREE=	yes

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

do-build:
	@${RM} -Rf ${WRKSRC}/docsrc

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@find ${WRKDIR} -name '*~' -exec ${RM} {} \;
	@find ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKSRC}/* ${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include <bsd.port.mk>
