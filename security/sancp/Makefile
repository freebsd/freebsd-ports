# New ports collection makefile for:	sancp
# Date created:				10 Feb 2005
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sancp
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sancp

PATCH_SITES=	http://sancp.sourceforge.net/
PATCHFILES=	sancp-1.6.1.fix200511.a.patch \
		sancp-1.6.1.fix200511.b.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A network connection profiler

ALL_TARGET=	final
USE_RC_SUBR=	sancp.sh
SUB_FILES=	pkg-message

PORTDOCS=	CHANGES INSTALL ISSUES README SETUP fields.LIST

.include <bsd.port.pre.mk>

post-install:
	${SH} ${PKGINSTALL}
	${INSTALL_PROGRAM} ${WRKSRC}/sancp ${PREFIX}/bin
.for f in sancp.conf
	${INSTALL_DATA} ${WRKSRC}/etc/sancp/${f} ${PREFIX}/etc/${f}-dist
	[ -f ${PREFIX}/etc/${f} ] || \
		${INSTALL_DATA} ${WRKSRC}/etc/sancp/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE ${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
