# ex:ts=8
# New ports collection makefile for:	bash
# Date created:		21 August 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	bash
PORTVERSION=	2.05b.007
PORTREVISION?=	2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cwru.edu/pub/bash/
MASTER_SITE_SUBDIR=	bash
DISTFILES=	bash-${PORTVERSION:C/\....$//}.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	bash-doc-${PORTVERSION:C/\....$//}.tar.gz
.endif

PATCH_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cwru.edu/pub/bash/bash-2.05b-patches/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	bash/bash-2.05b-patches obrien
PATCHFILES=	bash205b-001 bash205b-002 bash205b-003 bash205b-004 \
		bash205b-005 bash205b-006 bash205b-007
#		msg00029.txt msg00031.txt msg00030.txt

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	The GNU Bourne Again Shell

.include <bsd.port.pre.mk>

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/bash-${PORTVERSION:C/\....$//}
GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--with-installed-readline
.if defined(WANT_STATIC_BASH) || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ( ${NOSHARED} != "no" && ${NOSHARED} != "NO" ))
CONFIGURE_ENV=	LDFLAGS=-static
.else
CONFIGURE_ARGS+= --enable-static-link=no
.endif
MAN1=		bash.1 bashbug.1

post-patch:
	@${REINPLACE_CMD} -e "s,.FN /bin/bash,.FN ${PREFIX}/bin/bash," \
		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}/doc/bash.1

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak; ${ECHO_CMD} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${DOCSDIR}
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.txt  \
		${DOCSDIR}
	${BZIP2_CMD} -f ${DOCSDIR}/*.ps
.endif

.include <bsd.port.post.mk>

CONFIGURE_TARGET:=	--build=${CONFIGURE_TARGET}
