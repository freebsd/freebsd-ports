# Created by: obonilla
# $FreeBSD$

PORTNAME=	nam
PORTVERSION=	1.15
CATEGORIES=	net
MASTER_SITES=	SF/ns${PORTNAME}/${PORTNAME}-1/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Animation tool for network simulation traces

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
LIB_DEPENDS=	otcl.1:${PORTSDIR}/lang/otcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	xmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER} --x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
USE_GMAKE=	yes
USE_TK=		85+
ALL_TARGET=	${PORTNAME}

MAN1=		nam.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ex/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
