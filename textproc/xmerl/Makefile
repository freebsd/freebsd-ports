# New ports collection makefile for:	xmerl
# Date Created:				5 March 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmerl
PORTVERSION=	0.19
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sowap
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for XML processing in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GMAKE=	yes

XMERL=		${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}

do-install:
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${LN} -s ${DOCSDIR} ${XMERL}/doc
.endif

	@for SUBDIR in ebin inc src; do \
		${MKDIR} ${XMERL}/$${SUBDIR}; \
		${CP} -r ${WRKSRC}/$${SUBDIR}/* ${XMERL}/$${SUBDIR}; \
		${CHMOD} ${SHAREMODE} ${XMERL}/$${SUBDIR}/*; \
	done

	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XMERL}
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
