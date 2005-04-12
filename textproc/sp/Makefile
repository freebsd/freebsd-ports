# New ports collection makefile for:	sp
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	sp
PORTVERSION=	1.3.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An object-oriented toolkit for SGML parsing and entity management

.if ${MACHINE_ARCH} == sparc64
BROKEN=		does not compile on ${MACHINE_ARCH}
.endif

USE_SUBMAKE=	yes
INSTALLS_SHLIB=	yes
USE_GCC=	2.95
USE_REINPLACE=	yes
PORTDOCS=	Makefile archform.htm build.htm catalog catalog.htm \
		charset.htm features.htm generic.htm ideas.htm index.htm \
		new.htm nsgmls.htm sgmldecl.htm sgmlnorm.htm sgmlsout.htm \
		spam.htm spent.htm sx.htm sysdecl.htm sysid.htm xml.htm

post-patch:
	${REINPLACE_CMD} -e 's,=/usr/local,=${PREFIX},g' ${WRKSRC}/Makefile*

post-install:
	${MKDIR} ${PREFIX}/include/sp
	${RM} -f ${WRKSRC}/include/*.orig
	for f in ${WRKSRC}/include/*;do ${INSTALL_DATA} $$f ${PREFIX}/include/sp;done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
