# New ports collection makefile for:   bpft
# Date created:			26 August 2002
# Whom:				El Vampiro <vampiro@rootshell.ru>
#
# $FreeBSD$

PORTNAME=	bpft
PORTVERSION=	4.20040414
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=bpft4
DISTNAME=	bpft4-2004-04-14
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The BPF Traffic collector

CONFLICTS=	trafd-3.0.*

WRKSRC=		${WRKDIR}/bpft
MAN1=		traflog.1 trafstat.1
MAN8=		trafstatd.8 trafd.8
PORTDOCS=	README WhatsNew
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/include/pathnames.h
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<net/slip.h>|"../linux-include/net/slip.h"|' \
		${WRKSRC}/lib/interfaces.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
