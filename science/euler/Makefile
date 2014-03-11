# Created by: ijliao
# $FreeBSD$

PORTNAME=	euler
PORTVERSION=	1.61.0
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.61
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program computes with real and complex numbers and matrices

LICENSE=	GPLv2

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g ; \
		 /^install-data-am/s|install-eulerdocDATA||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/d ; \
		 /-Wall/d ; \
		 /-O3/d' ${WRKSRC}/src/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} ${BINMODE}
.endif

.include <bsd.port.post.mk>
