# New ports collection makefile for:   bpft
# Date created:			26 August 2002
# Whom:				El Vampiro <vampiro@rootshell.ru>
#
# $FreeBSD$

PORTNAME=	bpft
PORTVERSION=	4.20031028
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=bpft4
DISTNAME=	bpft4-latest
EXTRACT_SUFX=	.tgz

MAINTAINER=	aquatique@rusunix.org
COMMENT=	The BPF Traffic collector

BROKEN=		"Changes permissions of system directories"

CONFLICTS=	trafd-3.0.*

WRKSRC=		${WRKDIR}/bpft
MAN1=		traflog.1 trafstat.1
MAN8=		trafstatd.8 trafd.8
MANCOMPRESSED=	yes
USE_REINPLACE=	yes

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!!                         WARNING                           !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG}
	@${ECHO_MSG} "This port uses original trafd binaries layout"
	@${ECHO_MSG} "Original trafd and bpft binaries layout are mutually exclusive"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/include/pathnames.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/WhatsNew ${DOCSDIR}
.endif

.include <bsd.port.mk>
