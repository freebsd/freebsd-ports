# New ports collection makefile for:	xmerl
# Date Created:				5 March 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmerl
PORTVERSION=	0.18
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sowap
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for XML processing in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erlc:${PORTSDIR}/lang/erlang

USE_GMAKE=	yes

XMERL_DOCS=	README.html changes.txt xpath-grammar.txt xslt-example.dtd xslt-example.xls

do-install:
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${XMERL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done

	@${MKDIR} ${PREFIX}/lib/erlang/lib/xmerl

	@for FILE in ebin inc priv src; do \
		${MKDIR} ${PREFIX}/lib/erlang/lib/xmerl/$${FILE}; \
		${CP} -r ${WRKSRC}/$${FILE}/* \
			${PREFIX}/lib/erlang/lib/xmerl/$${FILE}; \
		${CHMOD} ${SHAREMODE} \
			${PREFIX}/lib/erlang/lib/xmerl/$${FILE}/*; \
	done

	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/erlang/lib/xmerl

.include <bsd.port.mk>
