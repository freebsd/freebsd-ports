# Ports collection makefile for:	chkrootkit
# Date created:				13 Mar 2001
# Whom:					Luiz Eduardo R. Cordeiro
#
# $FreeBSD$
#

PORTNAME=	chkrootkit
PORTVERSION=	0.45
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pangeia.com.br/pub/seg/pac/ \
		ftp://gd.tuwien.ac.at/infosys/security/chkrootkit/ \
		ftp://ftp.digitalvoodoo.org/pub/mirrors/chkrootkit/ \
		http://www.spenneberg.org/chkrootkit-mirror/files/ \
		http://www.mirrors.wiretapped.net/security/host-security/chkrootkit/ \
		http://ftp.uni-stuttgart.de/pub/security/unix/forensics/chkrootkit/ \
		http://ftp.bit.nl/mirror/chkrootkit/ \
		http://chkrootkit.mirror.fr/

MAINTAINER=	cordeiro@nic.br
COMMENT=	A tool to locally check for signs of a rootkit

USE_REINPLACE=	yes

ALL_TARGET=	chkrootkit chklastlog chkwtmp chkutmp chkproc chkdirs ifpromisc check_wtmpx strings

PLIST_FILES=	${ALL_TARGET:C,^,sbin/,}

.if !defined(NOPORTDOCS)
PORTDOCS=	ACKNOWLEDGMENTS COPYRIGHT README README.chklastlog README.chkwtmp
.endif

BINMODE=	0700

pre-patch:
	${REINPLACE_CMD} -e "s/^CC/#CC/; s/^CFLAGS/#CFLAGS/" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		's#\./chklastlog#${PREFIX}/sbin/chklastlog#g; \
		s#\./chkwtmp#${PREFIX}/sbin/chkwtmp#g; \
		s#\./chkutmp#${PREFIX}/sbin/chkutmp#g; \
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
	${INSTALL_PROGRAM} ${WRKSRC}/chkutmp    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chkproc    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/chkdirs    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ifpromisc  ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/check_wtmpx  ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/strings  ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
