# New ports collection makefile for:	ess
# Date created: 06 March 2010
# Whom: 	Christopher J.s Ruwe
#
# $FreeBSD$
#

PORTNAME=	ess
PORTVERSION=	5.14
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/downloads/ess/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjr@cruwe.de
COMMENT=	R support for Emacsen

LICENSE=	GPLv2

RUN_DEPENDS=	R:${PORTSDIR}/math/R

USE_EMACS=	yes
USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
INFO=	ess
.endif

post-patch:
	${REINPLACE_CMD} -e "\|^PREFIX=|d" -e "\|^INSTALL=|d" \
		-e "\|^EMACS=|s|=.*|=${EMACS_NAME}|" \
		-e "\|^ETCDIR=|s|=.*|=${PREFIX}/${EMACS_LIBDIR}/etc/ess|" \
		-e "\|^INFODIR=|s|=.*|=${PREFIX}/${INFO_PATH}|" \
		-e "\|^LISPDIR=|s|=.*|=${PREFIX}/${EMACS_SITE_LISPDIR}|" \
		${WRKSRC}/Makeconf
	${REINPLACE_CMD} -e "\|cd doc; \$$(MAKE) \$$@|d" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|\$$(INSTALL)|${INSTALL_DATA}|g" \
		${WRKSRC}/doc/Makefile ${WRKSRC}/etc/Makefile
	${REINPLACE_CMD} -e "s|\$$(INSTALL)|${INSTALL_SCRIPT}|g" \
		${WRKSRC}/lisp/Makefile

.if !defined(NOPORTDOCS)
post-build:
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} info)
.endif

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install-info)
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
