# New ports collection makefile for:	xmerl
# Date Created:				5 March 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmerl
PORTVERSION=	0.19
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sowap
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for XML processing in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erlc:${PORTSDIR}/lang/erlang

USE_GMAKE=	yes

do-install:
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

	@${MKDIR} ${PREFIX}/lib/erlang/lib/${PORTNAME}

	@for FILE in ebin inc src; do \
		${MKDIR} ${PREFIX}/lib/erlang/lib/${PORTNAME}/$${FILE}; \
		${CP} -r ${WRKSRC}/$${FILE}/* \
			${PREFIX}/lib/erlang/lib/${PORTNAME}/$${FILE}; \
		${CHMOD} ${SHAREMODE} \
			${PREFIX}/lib/erlang/lib/${PORTNAME}/$${FILE}/*; \
	done

	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
