# ex:ts=8
#
# New ports collection makefile for:	envelope
# Date created:		2002/03/24
# Whom:			Alan Eldridge alane@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	envelope
PORTVERSION=	1.0.0
CATEGORIES=	print
MASTER_SITES=	http://freefall.homeip.net/code/envelope/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line Postscript envelope printer

NO_BUILD=	yes
USE_PERL5=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB+=	DOCSDIR=${DOCSDIR:S@^${PREFIX}/@@}
PLIST_SUB+=	EXAMPLESDIR=${EXAMPLESDIR:S@^${PREFIX}/@@}

post-patch:
	@${REINPLACE_CMD} -e 's@/usr/bin/perl@${PERL}@' ${WRKDIR}/envelope

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/envelope ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/config
	@cd ${WRKDIR}; ${INSTALL_DATA} samplerc INSTALL ReadMe ${DOCSDIR}
	@cd ${WRKDIR}/examples; \
	${INSTALL_DATA} normal returnaddress shipping_label \
		simple with_config with_font_info with_options \
		${EXAMPLESDIR}
	@cd ${WRKDIR}/examples; ${INSTALL_DATA} config/* ${EXAMPLESDIR}/config
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
