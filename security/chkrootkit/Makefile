# Ports collection makefile for:	chkrootkit
# Date created:				13 Mar 2001
# Whom:					Luiz Eduardo R. Cordeiro
#
# $FreeBSD$
#

PORTNAME=	chkrootkit
PORTVERSION=	0.30
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pangeia.com.br/pub/seg/pac/
DISTNAME=	${PORTNAME}

MAINTAINER=	cordeiro@iqm.unicamp.br

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	chkrootkit chklastlog chkwtmp ifpromisc

pre-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	@${SED} -e "s/^CC/#CC/g" -e "s/^CFLAGS/#CFLAGS/g" \
		${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/chkrootkit ${WRKSRC}/chkrootkit.orig
	@${SED} -e 's#\./chklastlog#${PREFIX}/sbin/chklastlog#' \
		-e 's#\./chkwtmp#${PREFIX}/sbin/chkwtmp#' \
		-e 's#\./ifpromisc#${PREFIX}/sbin/ifpromisc#' \
		${WRKSRC}/chkrootkit.orig > ${WRKSRC}/chkrootkit
do-install:
	${INSTALL_SCRIPT}  ${WRKSRC}/chkrootkit ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chklastlog ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chkwtmp    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ifpromisc  ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/share/doc/chkrootkit
	${CP} -R ${WRKSRC}/COPY*   ${PREFIX}/share/doc/chkrootkit
	${CP} -R ${WRKSRC}/README* ${PREFIX}/share/doc/chkrootkit

.include <bsd.port.mk>
