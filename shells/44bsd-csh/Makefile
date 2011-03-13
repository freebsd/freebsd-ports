# ex:ts=8
# Ports collection makefile for:  csh
# Date created:			  23 January 2000
# Whom:				  David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#
PORTNAME=	44bsd-csh
PORTVERSION=	20001106
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The traditional 4.4BSD /bin/csh C-shell

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_BZIP2=	yes

NO_WRKSUBDIR=	yes
MAN1=		44bsd-csh.1
PORTDOCS=	paper.ascii.gz
post-extract:
	cd ${WRKSRC} ; co RCS/*,v
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

.include <bsd.port.mk>
