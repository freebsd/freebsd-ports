# New ports collection makefile for:	pop3proxy
# Date created:		11.05.04
# Whom:			Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	pop3proxy
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://people.freebsd.org/~mbr/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	POP3 Proxy Server derived from UP IMAP Proxy

BROKEN=		Checksum mismatch

GNU_CONFIGURE=	YES
USE_AUTOCONF_VER=213
USE_RC_SUBR=	YES

SAMPLE_EXT=	sample

.include <bsd.port.pre.mk>

RC_SCRIPTS_SUB= PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pop3proxyd.conf > ${WRKSRC}/pop3proxyd.conf ;
	if [ ! -f ${PREFIX}/etc/pop3proxyd.conf ]; then \
		${INSTALL} -c ${WRKSRC}/pop3proxyd.conf ${PREFIX}/etc/pop3proxyd.conf ; \
	fi
	${INSTALL} -c ${WRKSRC}/pop3proxyd.conf ${PREFIX}/etc/pop3proxyd.conf.${SAMPLE_EXT} ;
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pop3proxyd.sh > ${WRKSRC}/pop3proxyd.sh
	${INSTALL_SCRIPT} ${WRKSRC}/pop3proxyd.sh ${PREFIX}/etc/rc.d/pop3proxyd.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
