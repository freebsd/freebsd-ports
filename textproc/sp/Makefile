# New ports collection makefile for:	sp
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	sp
PORTVERSION=	1.3.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/ \
		http://dist.bsdlab.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An object-oriented toolkit for SGML parsing and entity management

CONFLICTS=	jade-1.*

.if ${MACHINE_ARCH} == sparc64
BROKEN=		"does not compile on ${MACHINE_ARCH}"
.endif

USE_SUBMAKE=	yes
USE_LDCONFIG=	yes
USE_GCC=	2.95
PORTDOCS=	Makefile archform.htm build.htm catalog catalog.htm \
		charset.htm features.htm generic.htm ideas.htm index.htm \
		new.htm nsgmls.htm sgmldecl.htm sgmlnorm.htm sgmlsout.htm \
		spam.htm spent.htm sx.htm sysdecl.htm sysid.htm xml.htm

DEPRECATED=	unmaintained, does not work with current versions of GCC, needs gcc295 which has been failing to build for months
EXPIRATION_DATE=2009-04-28

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
