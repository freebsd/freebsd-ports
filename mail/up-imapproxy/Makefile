# New ports collection makefile for:	imapproxy
# Date created:		11.05.04
# Whom:			Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	up-imapproxy
PORTVERSION=	1.2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.imapproxy.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	A caching IMAP proxy server

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
USE_RC_SUBR=	YES

SAMPLE_EXT=	sample

.include <bsd.port.pre.mk>

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-patch:
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g; s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/imapproxyd.conf > ${WRKSRC}/imapproxyd.conf ;
	${INSTALL} -m 644 -c ${WRKSRC}/imapproxyd.conf ${PREFIX}/etc/imapproxyd.conf.default ;
	@if [ ! -f ${PREFIX}/etc/imapproxyd.conf ]; then \
		${INSTALL} -m 644 -c ${WRKSRC}/imapproxyd.conf ${PREFIX}/etc/imapproxyd.conf ; \
	fi
	${INSTALL} -m 644 -c ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf.${SAMPLE_EXT} ;
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/imapproxyd.sh > ${WRKSRC}/imapproxyd.sh
	${INSTALL_SCRIPT} -m 755 ${WRKSRC}/imapproxyd.sh ${PREFIX}/etc/rc.d/imapproxyd.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
