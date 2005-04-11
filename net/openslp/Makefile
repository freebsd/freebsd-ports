# New ports collection makefile for:    OpenSLP 1.0
# Date created:		15 Sep 2001
# Whom:			Joe Clarke
#
# $FreeBSD$
#

PORTNAME=	openslp
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openslp

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Open-source implementation of the Service Location Protocol

.if defined(WITH_SLP_SECURITY)
USE_OPENSSL=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/openslp \
		--localstatedir=/var
CONFIGURE_TARGET=	--target=${ARCH}-unknown-freebsd${OSREL}

.if defined(WITH_SLP_SECURITY)
CONFIGURE_ARGS+=	--enable-slpv2-security
.endif

.if defined(WITH_ASYNC_API)
CONFIGURE_ARGS+=	--enable-async-api
.endif

INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "OpenSLP has the following tunable option(s):"
	@${ECHO_MSG} "		WITH_SLP_SECURITY=yes	Turns on SLPv2 security support"
	@${ECHO_MSG} "		WITH_ASYNC_API=yes	Enable asynchronous communication API"
	@${ECHO_MSG} ""

post-extract:
	@(cd ${WRKSRC}; \
		${FIND} doc -type f -path '*/CVS/*' -delete; \
		${FIND} doc -type d -name CVS -delete)
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/slpd.sh.sample > ${WRKSRC}/slpd.sh

post-install:
.for FILE in slp.conf slp.reg slp.spi
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} ${PREFIX}/etc/openslp/${FILE}.default
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/slpd.sh ${PREFIX}/etc/rc.d/001slpd.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc; \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;)
.endif

.include <bsd.port.mk>
