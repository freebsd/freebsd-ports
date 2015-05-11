# Created by: Christopher J. Ruwe
# $FreeBSD$

PORTNAME=	ess
DISTVERSION=	14.09
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/downloads/ess/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjr@cruwe.de
COMMENT=	R support for Emacsen

LICENSE=	GPLv2

RUN_DEPENDS=	R:${PORTSDIR}/math/R

USE_EMACS=	yes
USES=		gmake

OPTIONS_DEFINE=	DOCS

DOCS_USES=	makeinfo
DOCS_INFO=	ess

.include <bsd.port.options.mk>

#attention, dirty hack: because 'ETCDIR =' is typed _with_ trailing
#space in Makefile, $STAGEDIR append fails without the additional
#space in the port
post-patch: .SILENT
	${REINPLACE_CMD} -e "\|^PREFIX=|d" -e "\|^INSTALL=|d" \
		-e "\|^EMACS=|s|=.*|=${EMACS_NAME}|" \
		-e "\|^ETCDIR\ =|s|=.*|=${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess|" \
		-e "\|^INFODIR=|s|=.*|=${STAGEDIR}${PREFIX}/${INFO_PATH}|" \
		-e "\|^LISPDIR=|s|=.*|=${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}|" \
		-e "\|^SITELISP=|d" \
		${WRKSRC}/Makeconf
	${REINPLACE_CMD} -e "\|cd doc; \$$(MAKE) \$$@|d" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|\$$(INSTALL)|${INSTALL_DATA}|g" \
		${WRKSRC}/doc/Makefile ${WRKSRC}/etc/Makefile
	${REINPLACE_CMD} -e "s|\$$(INSTALL)|${INSTALL_SCRIPT}|g" \
		${WRKSRC}/lisp/Makefile

post-build:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} \
		${MAKE_ARGS} info)
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} \
		${MAKE_ARGS} install-info)
.endif

.include <bsd.port.mk>
