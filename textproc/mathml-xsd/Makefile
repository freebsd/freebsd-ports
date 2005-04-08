# ex:ts=8
# Ports collection makefile for:	mathml-xsd
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mathml-xsd
PORTVERSION=	2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/Math/XMLSchema/
DISTNAME=	mathml${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MathML XML Schema

NO_BUILD=	yes

post-extract:
	@${FIND} ${WRKSRC} -name "CVS" -type d -delete

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/* ${DATADIR}
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
