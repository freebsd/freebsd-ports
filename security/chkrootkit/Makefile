# Ports collection makefile for:	chkrootkit
# Date created:				13 Mar 2001
# Whom:					Luiz Eduardo R. Cordeiro
#
# $FreeBSD$
#

PORTNAME=	chkrootkit
PORTVERSION=	0.41
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=	cordeiro@luinil.nic.br
COMMENT=	A tool to locally check for signs of a rootkit

USE_REINPLACE=	yes

ALL_TARGET=	chkrootkit chklastlog chkwtmp chkproc chkdirs ifpromisc check_wtmpx strings

DOCFILES=	COPYRIGHT README README.chklastlog README.chkwtmp

BINMODE=	0700

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
IGNORE=		"Reports false positives on 5.x"
.endif

pre-patch:
	${REINPLACE_CMD} -e "s/^CC/#CC/; s/^CFLAGS/#CFLAGS/" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		's#\./chklastlog#${PREFIX}/sbin/chklastlog#g; \
		s#\./chkwtmp#${PREFIX}/sbin/chkwtmp#g; \
		s#\./chkproc#${PREFIX}/sbin/chkproc#g; \
		s#\./chkdirs#${PREFIX}/sbin/chkdirs#g; \
		s#\./check_wtmpx#${PREFIX}/sbin/check_wtmpx#g; \
		s#\./strings#${PREFIX}/sbin/strings#g; \
		s#\./ifpromisc#${PREFIX}/sbin/ifpromisc#g;' \
		${WRKSRC}/chkrootkit

do-install:
	${INSTALL_SCRIPT}  ${WRKSRC}/chkrootkit ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chklastlog ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chkwtmp    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chkproc    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chkdirs    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ifpromisc  ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/check_wtmpx  ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/strings  ${PREFIX}/sbin
.if	!defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/chkrootkit
	${INSTALL_DATA} ${DOCFILES:C,^,${WRKSRC}/,} ${PREFIX}/share/doc/chkrootkit
.endif

.include <bsd.port.post.mk>
