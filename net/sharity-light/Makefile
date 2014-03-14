# Created by: Dmitrij Tejblum <dima@tejblum.dnttm.rssi.ru>
# $FreeBSD$

PORTNAME=	sharity-light
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.obdev.at/ftp/pub/Products/Sharity-Light/
DISTNAME=	Sharity-Light.1.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userland smbfs --- SMB to NFS protocols converter

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
MAN8=		smbmount.8

PLIST_FILES=	sbin/shlight sbin/unshlight
PORTDOCS=	*

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WRKDIR}/unshlight
	@${CP} ${FILESDIR}/unshlight.c ${WRKDIR}/unshlight
	@${CP} ${FILESDIR}/Makefile.unshlight ${WRKDIR}/unshlight/Makefile

post-patch:
	${REINPLACE_CMD} -e "s,#.*include <nfs/rpcv2.h>,," ${WRKSRC}/nfs/syscalls.c

post-build:
	cd ${WRKDIR}/unshlight && make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shlight ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unshlight/unshlight ${PREFIX}/sbin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/FAQ.txt ${DOCSDIR}/FAQ
.endif
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
