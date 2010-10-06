# New ports collection makefile for:    psmisc
# Date created:         10 March 1998
# Whom:                 rantapaa@uswest.net
#
# $FreeBSD$
#

PORTNAME=	psmisc
PORTVERSION=	22.13
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	A port of the Linux pstree, killall and pidof commands

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

CONFLICTS=	pidof-[0-9]* pstree-2.[0-9]*

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	NLS "Native Language Support via gettext utilities" on

.include <bsd.port.options.mk>

MAN1=		killall.1 pstree.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-nls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^#define COMM_LEN / s|16|254|' ${WRKSRC}/src/comm.h

post-install:
	@${LN} -fs killall ${PREFIX}/bin/pidof

.include <bsd.port.mk>
