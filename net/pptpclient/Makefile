# New ports collection makefile for:	pptpclient
# Date created:				19 June 1999
# Whom:					John Polstra <jdp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pptpclient
PORTVERSION=	1.7.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/pptp/pptp-${PORTVERSION}
DISTNAME=	pptp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

USE_PERL5=	yes

MAN8=		pptp.8 pptpsetup.8
FILES=		README ppp.conf
PORTDOCS=	AUTHORS COPYING ChangeLog DEVELOPERS INSTALL NEWS \
		PROTOCOL-SECURITY README TODO USING

MAKE_ARGS=	DEBUG=""

post-patch:
	${REINPLACE_CMD} -e 's|/usr|/usr/local|g' -e 's|/etc|/usr/local/etc|g' \
	${WRKSRC}/Makefile
	${REINPLACE_CMD} 's|/etc|/usr/local/etc|g' ${WRKSRC}/pptpsetup

do-install:
	${MKDIR} ${EXAMPLESDIR} ${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/pptpsetup ${PREFIX}/sbin
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/,} ${MAN8PREFIX}/man/man8
	${INSTALL_DATA} ${FILES:S,^,${FILESDIR}/,} ${EXAMPLESDIR}
	${CP} ${FILESDIR}/ppp.conf ${ETCDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
