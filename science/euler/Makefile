# ex:ts=8
# Ports collection Makefile for:	euler
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	euler
PORTVERSION=	1.61.0
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.61
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program computes with real and complex numbers and matrices

USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g ; \
		 /^install-data-am/s|install-eulerdocDATA||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/d ; \
		 /-Wall/d ; \
		 /-O3/d' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} ${BINMODE}
.endif

.include <bsd.port.post.mk>
