# ex:ts=8
# Ports collection makefile for:	xhtml1-xsd
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xhtml1-xsd
PORTVERSION=	200208
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/2002/08/xhtml/
DISTFILES=	xhtml1-frameset.xsd \
		xhtml1-strict.xsd \
		xhtml1-transitional.xsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XHTML 1.0 (Second Edition) in XML Schema

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/* ${DATADIR}
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
