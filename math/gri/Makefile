# New ports collection makefile for: gri
# Date created:		14 Oct 2000
# Whom:			M. L. Dodson, <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	gri
PORTVERSION=	2.12.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	gri-${PORTVERSION}-arch-indep

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible plotting language for producing scientific graphs

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	YES
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if defined(NOPORTDOCS)
ALL_TARGET=	gri
INSTALL_TARGET=	install-bin
.endif

MAN1=	gri.1 gri_merge.1 gri_unpage.1

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info* ${WRKSRC}/doc/info
	@${MV} -f ${WRKSRC}/doc/gri-manpage.1 ${WRKSRC}/doc/gri.1

post-patch:
	@${REINPLACE_CMD} -e "s/makeinfo/makeinfo --no-split/" ${WRKSRC}/doc/Makefile

post-install:
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/doc/gri.info ${PREFIX}/info
	install-info ${PREFIX}/info/gri.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
