# New ports collection makefile for:	iselect
# Date created:		03-Jan-1998
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	iselect
PORTVERSION=	1.4.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	tool/iselect

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive Selection Tool

GNU_CONFIGURE=	yes

MAN1=		iselect.1

.if defined(WITH_SLANG)
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=	--with-incdir=${LOCALBASE}/include \
			--with-libdir=${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iselect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iselect.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
