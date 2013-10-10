# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$
PORTNAME=	44bsd-csh
PORTVERSION=	20001106
PORTREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The traditional 4.4BSD /bin/csh C-shell

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if  ${OSVERSION} >= 1000055
BUILD_DEPENDS=    rcs:${PORTSDIR}/devel/rcs57
.endif

NO_WRKSUBDIR=	yes
MAN1=		44bsd-csh.1
PORTDOCS=	paper.ascii.gz
NO_STAGE=	yes
post-extract:
	cd ${WRKSRC} ; co RCS/*,v; chmod u+w *
	cd ${WRKSRC}/USD.doc ; co RCS/*,v

post-build:
	cd ${WRKSRC}/USD.doc ; ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csh ${PREFIX}/bin/44bsd-csh
	${INSTALL_MAN} ${WRKSRC}/csh.1 ${PREFIX}/man/man1/44bsd-csh.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/USD.doc/paper.ascii.gz ${DOCSDIR}
.endif
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/44bsd-csh /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/44bsd-csh) > /etc/shells
	@${RM} /etc/shells.bak

tarup:
	cd ${WRKSRC} ; rm * USD.doc/*
	cd ${WRKSRC} ; ${TAR} cvyf /tmp/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

.include <bsd.port.post.mk>
