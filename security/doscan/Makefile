# New ports collection makefile for:	doscan
# Date created:		24 Sept 2003
# Whom:			Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	doscan
PORTVERSION=	0.2.6
CATEGORIES=	security net
MASTER_SITES=	http://static.enyo.de/fw/releases/doscan/

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Tool to quickly scan your network for machines listening on a TCP port

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
DOC_FILES=	README
MAN1=		doscan.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/freebsd4.diff
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
